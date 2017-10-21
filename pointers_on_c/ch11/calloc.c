#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *calloc(size_t nmemb, size_t size) {
	void *mem;

	if (nmemb == 0 || size == 0)
		return NULL;

	size *= nmemb;
	mem = malloc(size);
	if (!mem)
		return NULL;

	memset(mem, 0, size);
	return mem;
}

int main(void)
{
	char *buf = calloc(4, 10);

	buf[0] = 'H';
	buf[1] = 'e';
	buf[2] = 'l';
	buf[3] = 'l';
	buf[4] = 'o';

	printf("%s\n", buf);

	return 0;
}
