#include <stdio.h>
#include <stdlib.h>

char *readchar(void)
{
	char *array = NULL;
	int readsize = 0;
	int arraysize = 0;
	int ret, ch;

	while ((ch = getchar()) != EOF) {
		if (arraysize <= readsize + 1) {
			arraysize += 4;
			array = realloc(array, arraysize * sizeof(*array));
			if (!array)
				goto error;
		}
		array[readsize] = ch;
		readsize += 1;
	}
	array[arraysize] = '\0';

error:
	return array;
}

int main(void)
{
	char *array;

	array = readchar();
	if (!array)
		return 1;

	printf("%s\n", array);

	free(array);

	return 0;
}
