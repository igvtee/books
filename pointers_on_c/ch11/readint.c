#include <stdio.h>
#include <stdlib.h>

int *readint(void)
{
	int *array = NULL;
	int readsize = 0;
	int arraysize = 0;
	int ret, num;

	while ((ret = scanf("%d", &num)) != EOF) {
		if (ret == 0) {
			getchar();
			continue;
		}

		readsize += 1;
		if (arraysize <= readsize - 1) {
			arraysize += 4;
			array = realloc(array, arraysize * sizeof(*array));
			if (!array)
				goto error;
		}
		array[readsize] = num;
	}
	array[0] = readsize;

error:
	return array;
}

int main(void)
{
	int *array, *pnum;
	int num;

	array = readint();
	if (!array)
		return 1;

	num = array[0];
	pnum = array + 1;
	while (num--)
		printf("%d ", *pnum++);
	putchar('\n');

	free(array);

	return 0;
}
