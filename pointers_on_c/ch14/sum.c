#include <stdio.h>

#define SUM(value)	((value) + (value))
#define SIZE		10

int main(void)
{
	int i, sum;
	int array[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	/* sum all the values in the array. */
	sum = 0;
	i = 0;
	while (i < SIZE)
		sum += SUM(array[i++]);

	printf("sum: %d\n", sum);

	return 0;
}
