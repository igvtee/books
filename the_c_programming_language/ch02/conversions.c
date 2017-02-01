#include <stdio.h>

main()
{
	/* comparisons between signed and unsigned values are machine 
	 * dependent
	 */
	printf("-1L < 1U is %d\n", -1L < 1U);
	printf("-1L > 1UL is %d\n", -1L > 1UL);
	printf("-1L promoted to UL is %lu\n", (unsigned long)-1L);
}
