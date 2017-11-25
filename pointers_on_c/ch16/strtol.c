#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char const *str = " 4545 this is a number";
	char const *str1 = "0x2af4";
	long int num;
	unsigned long int unum;
	char *unused;
	
	num = strtol(str, &unused, 10);
	printf("%s\nnum: %ld, unused: '%s'\n", str,
			num, unused);

	unum = strtoul(str1, &unused, 0);
	printf("%s\nunum: %#lx, unused: '%s'\n", str1,
			unum, unused);

	return 0;
}
