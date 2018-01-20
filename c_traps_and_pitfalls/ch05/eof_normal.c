#include <stdio.h>

int main(void)
{
	register int c;

	/* getchar maybe macro so faster */
	while ((c = getchar()) != EOF)
		putchar(c);

	return 0;
}
