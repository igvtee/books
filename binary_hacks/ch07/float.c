#include <stdio.h>

double dmul(double a, double b)
{
	return a * b;
}

int main(void)
{
	unsigned long long int i, j;
	double f, g;

#ifdef __i386__
	{
		unsigned short cw;
		asm("fnstcw %0" : "=m" (cw));
		cw &= ~0x0300u;
		cw |= 0x0200u; /* double precision (64 bit) */
		asm("fldcw %0" : : "m" (cw));
	}
#endif

	i = 0x0008008000000000ull; /* 1.11281e-308 */
	j = 0x3ff0000000000001ull; /* 1.0 + alpha */
	printf("0x%016llx * 0x%016llx\n", i, j); /* uses i & j */

	f = *((double *)&i);
	g = *((double *)&j);
	printf("%g * %g =\n", f, g);

	f = dmul(f, g);
	i = *((unsigned long long int *)&f);
	printf("%g (0x%016llx)\n", f, i);

	return 0;
}
