#include <stdio.h>

int main(void)
{
	int a=-2;
	unsigned int b=1;
	/* fix by
	 * long c = a + (long)b;
	 */
	long c = a + b;
	long long d=c; // to get a consistent size for printing.

	printf("%lld\n", d);

	printf("long size: %zu\n", sizeof(long));
	printf("long long size: %zu\n", sizeof(long long));

	return 0;
}
