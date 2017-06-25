#include <stdio.h>

int main(void)
{
	int a = -3;
	unsigned int b = 8;

	printf("%d %d\n", a, ~a);
	printf("%u %u\n", b, ~b);

	return 0;
}
