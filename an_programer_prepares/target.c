#include <stdio.h>
#define PACKAGE 1
#define PACKAGE_VERSION 1
#include <bfd.h>

int main(void)
{
	const char ** t = bfd_target_list();
	while (*t) {
		printf("%s\n", *t);
		t++;
	}
	return 0;
}
