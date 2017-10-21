#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_heap_size(void)
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	long long unsigned beg, end;

	stream = fopen("/proc/self/maps", "r");
	if (stream == NULL)
		exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, stream)) != -1) {
		if (!strstr(line, "[heap]"))
			continue;
		if (sscanf(line, "%llx-%llx", &beg, &end) != 2)
			break;
		printf("%llx-%llx: %llx\n", beg, end, end - beg);
	}

	free(line);
	fclose(stream);

	return 0;
}

int main(void)
{
	size_t size;
	void *buf;

	get_heap_size();
	size = 500;
	if (!(buf = malloc(size))) {
		printf("malloc 500 error\n");
		return 1;
	}
	get_heap_size();
	free(buf);

	size = 5000;
	if (!(buf = malloc(size))) {
		printf("malloc 5000 error\n");
		return 1;
	}
	get_heap_size();
	free(buf);

	return 0;
}
