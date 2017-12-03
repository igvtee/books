#include <stdio.h>

int main(void)
{
	int x, y, z;
	/*
	 * maximal munch strategy
	 * z = y++ + x
	 */
	x = 10;
	y = 1;
	z = y+++x;
	printf("y is: %d, z is: %d\n", y, z);

	return 0;
}
