#include <stdio.h>

/* invert: inverts the n bits of x that begin at position p */
unsigned invert(unsigned x, int p, int n)
{
	return x ^ (~(~0 << n) << (p + 1 -n));
}

int main(void)
{
	unsigned x = 0xaaaaaaaa;
	int p = 4, n = 3;

	printf("%08x\n", invert(x, p, n));

	return 0;
}
