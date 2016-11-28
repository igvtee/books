#define _GNU_SOURCE
#include <stdio.h>
#include <link.h>

static int print_callback(struct dl_phdr_info *info, size_t size, void *data)
{
	printf("%p %s\n", (void *)info->dlpi_addr, info->dlpi_name);
	return 0;
}

int main(void)
{
	dl_iterate_phdr(print_callback, NULL);
	return 0;
}
