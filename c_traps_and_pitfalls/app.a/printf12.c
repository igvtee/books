#include <stdio.h>

int main(void)
{
	printf("o: %#o\nx: %#x\n", 0, 0x34);

	printf("%.0f %#.0f %g %#g\n",
			3.0, 3.0, 3.0, 3.0);

	return 0;
}
