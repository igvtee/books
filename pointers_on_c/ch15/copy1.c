#include <stdio.h>

int main(void)
{
	int ch;

	while ((ch = getchar()) != EOF)
		if (putchar(ch) == EOF) {
			perror("putchar ");
			break;
		}

	return 0;
}
