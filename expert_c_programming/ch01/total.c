#include <stdio.h>

int array[] = {23, 34, 12, 17, 204, 99, 16};
#define TOTAL_ELEMENTS (sizeof(array)/sizeof(array[0]))

int main(void)
{
	int d = -1;

	if (d <= TOTAL_ELEMENTS - 2)
		printf("d <= TOTAL_ELEMENTS - 2\n");
	else
		printf("d > TOTAL_ELEMENTS - 2\n");

	/*
	 * size_t is unsigned int. cause d(-1)
	 * convert to unsigned int (large integer)
	 */
	if (d <= (int)TOTAL_ELEMENTS - 2)
		printf("d <= TOTAL_ELEMENTS - 2\n");
	else
		printf("d > TOTAL_ELEMENTS - 2\n");

	return 0;
}
