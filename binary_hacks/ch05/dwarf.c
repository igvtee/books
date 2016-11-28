#include <elfutils/libdw.h>
#include <dwarf.h>
#include <libelf.h>

#include <stdio.h>
#include <fcntl.h>
#include <assert.h>

static void process_one_die(Dwarf_Debug dbg, Dwarf_Die die, int d) {
	Dwarf_Error err;
	int ret;

	while (1) {
		Dwarf_Half tag;
		Dwarf_Die child;

		ret = dwarf_tag(die, &tag, &err);
		assert(ret == DW_DLV_OK);

		if (tag == DW_TAG_variable || tag == DW_TAG_formal_parameter) {
			Dwarf_Attribute attr;
			Dwarf_Unsigned line;
			char *str;

			ret = dwarf_attr(die, DW_AT_decl_line, &attr, &err);
			if (ret == DW_DLV_NO_ENTRY)
				goto next;
			assert(ret == DW_DLV_OK);
			ret = dwarf_formudata(attr, &line, &err);
			assert(ret == DW_DLV_OK);

			ret = dwarf_attr(die, DW_AT_name, &attr, &err);
			assert(ret == DW_DLV_OK);
			ret = dwarf_formstring(attr, &str, &err);
			assert(ret == DW_DLV_OK);

			printf("%d: %s\n", (int)line, str);
		}

next:
		ret = dwarf_child(die, &child, &err);
		assert(ret != DW_DLV_ERROR);
		if (ret == DW_DLV_OK) {
			process_one_die(dbg, child, d+1);
		}

		ret = dwarf_siblingof(dbg, die, &die, &err);
		if (ret == DW_DLV_NO_ENTRY)
			break;
		assert(ret == DW_DLV_OK);
	}
}

static void process_one_file(Elf *elf, const char *filename)
{
	Dwarf_Debug dbg;
	Dwarf_Die die;
	Dwarf_Error err;
	int ret;

	Dwarf_Unsigned cu_header_length = 0;
	Dwarf_Unsigned abbrev_offset = 0;
	Dwarf_Half version_stamp = 0;
	Dwarf_Half address_size = 0;
	Dwarf_Unsigned next_cu_offset = 0;

	ret = dwarf_elf_init(elf, DW_DLC_READ, NULL, NULL, &dbg, &err);
	assert(ret == DW_DLV_OK);

	while ((ret = dwarf_next_cu_header(dbg, &cu_header_length,
					&version_stamp, &abbrev_offset,
					&address_size, &next_cu_offset,
					&err)) == DW_DLV_OK) {
		ret = dwarf_siblingof(dbg, NULL, &die, &err);

		if (ret == DW_DLV_OK) {
			process_one_die(dbg, die, 0);
		} else if (ret == DW_DLV_NO_ENTRY) {
			continue;
		}
		assert(ret == DW_DLV_OK);
	}

	assert(ret != DW_DLV_ERROR);
}

void dump_variables(const char *filename)
{
	int f;
	Elf_Cmd cmd;
	Elf *elf;
	elf_version(EV_CURRENT);

	f = open(filename, O_RDONLY);
	assert(f != -1);

	cmd = ELF_C_READ;
	elf = elf_begin(f, cmd, (Elf *)0);
	process_one_file(elf, filename);
	elf_end(elf);
}

int main(int argc, char *argv[])
{
	dump_variables(argv[0]);
	return 0;
}
