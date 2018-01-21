#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>

void alloc_arry(char *argv)
{
	uintmax_t arrayLength = strtoumax(argv, NULL, 10);
	void **array;

	array = malloc(sizeof(*array) * arrayLength);
	array[0] = NULL;

	/* remember to free(array) when you're done using it */
	free(array);
}

void alloc_array_new(char *argv)
{
	uintmax_t arrayLength = strtoumax(argv, NULL, 10);
	void *array[arrayLength];

	array[0] = &arrayLength;
	printf("%p\n", array[0]);
	/* no need to free array */
}

int main(void)
{
	char *argv = "20";

	alloc_arry(argv);
	alloc_array_new(argv);

	return 0;
}
