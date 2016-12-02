#define _GNU_SOURCE
#include <bfd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <sys/mman.h>
#include <dlfcn.h>

bfd *abfd;
asymbol **syms;

/* find hello symbol */
int get_hello_pos(void)
{
	long storage;
	int symnum;
	int i;
	int hello_pos = 0;

	storage = bfd_get_symtab_upper_bound(abfd);
	assert(storage >= 0);
	if (storage)
		syms = (asymbol **)malloc(storage);

	symnum = bfd_canonicalize_symtab(abfd, syms);
	assert(symnum >= 0);

	for (i = 0; i < symnum; i++) {
		asymbol *sym = syms[i];
		const char *name = bfd_asymbol_name(sym);
		if (strcmp(name, "hello") == 0) {
			hello_pos = abfd->origin + sym->section->filepos;
			break;
		}
	}
	assert(hello_pos);

	return hello_pos;
}

/* load hello.o to memory */
unsigned char *load_hello_o(char *filename)
{
	FILE *fp;
	int size = 0;
	unsigned char *hello_o;

	fp = fopen(filename, "rb");
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);

	fseek(fp, 0, SEEK_SET);
	hello_o = (unsigned char *)malloc(size);
	fread(hello_o, 1, size, fp);
	fclose(fp);

	return hello_o;
}

/* load rel.text section */
void reloc_hello_o(unsigned char *hello_o)
{
	asection *sect;
	arelent **loc;
	int size;
	int i;

	sect = bfd_get_section_by_name(abfd, ".text");
	size = bfd_get_reloc_upper_bound(abfd, sect);
	assert(size >= 0);

	loc = (arelent **)malloc(size);
	size = bfd_canonicalize_reloc(abfd, sect, loc, syms);
	assert(size >= 0);

	for (i = 0; i < size; i++) {
		arelent *rel = loc[i];
		int *p = (int *)(hello_o + sect->filepos + rel->address);
		asymbol *sym = *rel->sym_ptr_ptr;
		const char *name = sym->name;

		/* relocate section */
		if ((sym->flags & BSF_SECTION_SYM) != 0) {
			asection *s = bfd_get_section_by_name(abfd, name);
			*p += (int)hello_o + s->filepos;
		}
		/* relocate function */
		else {
			*p += (int)dlsym(RTLD_DEFAULT, name);
			if (rel->howto->pc_relative)
				*p -= (int)p;
		}
	}

	free(loc);
}

void invoke_hello(unsigned char *hello_o, int hello_pos)
{
	void (*hello_fp)() = (void (*)())(hello_o + hello_pos);
	int pagesize = (int)sysconf(_SC_PAGESIZE);
	char *p = (char *)((long)hello_fp & ~(pagesize - 1L));
	mprotect(p, pagesize * 10L, PROT_READ|PROT_WRITE|PROT_EXEC);

	hello_fp();
}

int main(void)
{
	int ret;
	int hello_pos, hello_size;
	unsigned char *hello_o;

	char *filename = "hello01.o";

	abfd = bfd_openr(filename, NULL);
	assert(abfd);
	ret = bfd_check_format(abfd, bfd_object);
	assert(ret);

	if (!(bfd_get_file_flags(abfd) & HAS_SYMS)) {
		assert(bfd_get_error() == bfd_error_no_error);
		bfd_close(abfd);
		return 1;
	}

	hello_pos = get_hello_pos();
	hello_o = load_hello_o(filename);
	reloc_hello_o(hello_o);

	free(syms);
	bfd_close(abfd);
	invoke_hello(hello_o, hello_pos);
	free(hello_o);

	return 0;
}
