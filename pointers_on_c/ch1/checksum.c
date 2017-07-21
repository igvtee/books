#include <stdio.h>

int main(void)
{
	int c;
	signed char checksum = -1;

	while ((c = getchar()) != EOF) {
		putchar(c);
		checksum += c;
		if (c == '\n')
			break;
	}
	printf("%d\n", checksum);

	return 0;
}
