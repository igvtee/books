#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <bfd.h>

void dump_symbols(const char *filename)
{
	bfd *abfd;
	asymbol *store;
	char *p;
	void *minisyms;
	int symnum, i;
	unsigned int size;
	int dyn = 0;
	int ret;

	abfd = bfd_openr(filename, NULL);
	assert(abfd);
	ret = bfd_check_format(abfd, bfd_object);
	assert(ret);

	if (!(bfd_get_file_flags(abfd) & HAS_SYMS)) {
		assert(bfd_get_error() == bfd_error_no_error);
		bfd_close(abfd);
		return;
	}

	store = bfd_make_empty_symbol(abfd);

	symnum = bfd_read_minisymbols(abfd, dyn, &minisyms, &size);
	assert(symnum >= 0);

	p = (char *)minisyms;
	for (i = 0; i < symnum; i++) {
		asymbol *sym = bfd_minisymbol_to_symbol(abfd, dyn, p, store);
		const char *name = bfd_asymbol_name(sym);
		bfd_vma value = bfd_asymbol_value(sym);
		printf("%p %s\n", (void *)value, name);
		p += size;
	}

	free(minisyms);
	bfd_close(abfd);
}

int main(int argc, char *argv[])
{
	dump_symbols(argv[0]);

	return 0;
}
