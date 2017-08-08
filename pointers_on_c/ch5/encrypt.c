#include <stdio.h>

int main(void)
{
	int c;

	while ((c = getchar()) != EOF)
		putchar(((c >= 'A' && c <= 'Z') ||
			 (c >= 'a' && c <= 'z'))?
			c + 13 : c);

	return 0;
}
