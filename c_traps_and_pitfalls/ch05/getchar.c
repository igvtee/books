#include <stdio.h>

int main(void)
{
	/* bug should be int */
	char c;

	while ((c = getchar()) != EOF)
		putchar(c);

	printf("%02hhx %x\n", c, EOF);

	return 0;
}
