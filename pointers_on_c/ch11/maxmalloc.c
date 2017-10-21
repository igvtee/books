#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	/* 1M */
	size_t max = 1024, min, size;
	void *buf;
	
	while ((buf = malloc(max)) != NULL) {
		max <<= 1;
		free(buf);
	}
	min = max >> 1;

	while (max > min) {
		size = (min + max) >> 1;
		if (size == min)
			break;
		buf = malloc(size);
		if (buf == NULL)
			max = size;
		else {
			min = size;
			free(buf);
		}
	}

	/* free ram size */
	printf("malloc max size: %zu\n", min);

	return 0;
}
