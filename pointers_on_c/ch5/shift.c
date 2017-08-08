#include <stdio.h>

int main(void)
{
	int num = -1;
	int shift = num >> 1;

	printf("%08x %08x\n", num, shift);

	if (num == shift)
		printf("arithmetic shift\n");
	else
		printf("logical shift\n");

	return 0;
}
