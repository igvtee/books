#include <stdio.h>

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p + 1 - n)) & ~(~0 << n);
}

/* setbits: set n bits of x at position p with bits of y */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	return x & ~(~(~0 << n) << (p + 1 - n)) |
		(y & ~(~0 << n) << (p + 1 -n));
}

int main(void)
{
	unsigned x = 0xaaaaaaaa;
	int p = 4, n = 3;
	unsigned y = 0xff00;

	printf("%08x %08x\n", getbits(x, p, n), setbits(x, p, n, y));

	return 0;
}
