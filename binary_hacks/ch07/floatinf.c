#include <stdio.h>

int main(void)
{
	unsigned long long int i, j, k;
	double f, g, h;

#ifdef __i386__
	{
		unsigned short cw;
		asm("fnstcw %0" : "=m" (cw));
		cw &= ~0x0300u;
		cw |= 0x0200u; /* double precision (64 bit) */
		asm("fldcw %0" : : "m" (cw));
	}
#endif

	i = 0x7fe0000000000000ull; /* 1.0 x 2^1024 */
	k = j = i;
	printf("%016llx, %016llx, %016llx\n", i, j, k); /* uses i, j and k */

	f = *((double *)&i);
	g = *((double *)&j);
	h = *((double *)&k);

	printf("%g + %g = %g = ", f, g, h);

	f += g;
	f -= h;
	printf("%g\n", f);

	return 0;
}
