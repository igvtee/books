#include <stdio.h>

int main(void)
{
	unsigned short a=1;
	/* fix by
	 * unsigned long b = ((long)a << 31);
	 */
	unsigned long b = (a << 31);
	unsigned long long c=b;

	printf("%llx\n", c);

	return 0;
}
