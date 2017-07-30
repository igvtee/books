#include <stdio.h>

int main(void)
{
	int ch, checksum;

	while ((ch = getchar()) != EOF) {
		checksum += ch;
		putchar(ch);
	}
	printf("Checksum = %d\n", checksum);

	return 0;
}
