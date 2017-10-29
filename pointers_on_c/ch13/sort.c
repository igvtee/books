#include <stdio.h>
#include <string.h>

void sort(char *data, int num, int size,
		int (*cmp)(const void *data1, const void *data2))
{
	int i, j;
	char (*array)[size] = (void *)data;
	char tmp[size];

	for (i = 0; i < num; i++) {
		for (j = i+1; j < num; j++) {
			if (cmp((void *)array[i], (void *)array[j]) > 0) {
				memcpy(tmp, array[j], size);
				memcpy(array[j], array[i], size);
				memcpy(array[i], tmp, size);
			}
		}
	}
}

int cmpint(const void *data1, const void *data2)
{
	return *(int *)data1 - *(int *)data2;
}

int main(void)
{
	int size = 5;
	int array[] = {9, 3, 1, 6, 7};
	int i;

	sort((void *)array, 5, sizeof(array[0]), cmpint);

	for (i = 0; i < size; i++)
		printf("%d ", array[i]);
	putchar('\n');

	return 0;
}
