#include <stdlib.h>
#include <stdio.h>

int *frequency(int size)
{
	int *array;
	int i;

	array = (int*)malloc(size * sizeof(*array));
	if (!array)
		return NULL;

	array -= 1;

	for (i = 1; i <= size; i++)
		array[i] = 0;

	while (scanf("%d", &i) == 1) {
		if (i < 1 || i > size)
			continue;
		array[i] += 1;
	}

	return array + 1;
}

int main(void)
{
	int *array;
	int size = 10;
	int i;

	if (!(array = frequency(size)))
		return 1;

	for (i = 0; i < size; i++)
		printf("%-3d: %d\n", i+1, array[i]);
	free(array);

	return 0;
}
