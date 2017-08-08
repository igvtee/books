#include <stdio.h>

int main(void)
{
	int c;

	while ((c = getchar()) != EOF)
		putchar((c >= 'A' && c <= 'Z') ?
			 c - 'A' + 'a' : c);

	return 0;
}
