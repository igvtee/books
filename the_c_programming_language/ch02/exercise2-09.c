#include <stdio.h>

/* bitcount: count 1 bits in x */
#if 1
int bitcount(unsigned x)
{
	int b = 0;

	for (b = 0; x != 0; x &= x - 1)
		b++;

	return b;
}
#else
int bitcount(unsigned x)
{
	int b;

	for (b = 0; x != 0; x >> 1)
		if (x & 01)
			b++;

	return b;
}
#endif

int main(void)
{
	printf("0x111 %d\n", bitcount(0x111));
	return 0;
}
