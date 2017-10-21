#include <stdio.h>

int main(void)
{
	/* when stack size 8192 kbytes */
	char array[8374900];

	printf("array size: %zu\n", sizeof(array));

	return 0;
}
