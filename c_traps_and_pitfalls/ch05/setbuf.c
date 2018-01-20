#include <stdio.h>

static char buf[BUFSIZ];

int main(void)
{
	int c;

	/* setbuf(stdout, malloc(BUFSIZ)) */
	setubf(stdout, buf);
	while ((c = getchar()) != EOF)
		putchar(c);

	return 0;
}
