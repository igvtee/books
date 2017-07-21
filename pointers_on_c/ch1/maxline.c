#include <stdio.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

int main(void)
{
	int size, max_size;
	char max_line[MAX_LINE_SIZE];
	char tmp[MAX_LINE_SIZE];

	max_size = 0;
	while (fgets(tmp, sizeof(tmp), stdin) != NULL) {
		size = strlen(tmp);
		if (size > max_size) {
			max_size = size;
			strcpy(max_line, tmp);
		}
	}

	printf("%s", max_line);

	return 0;
}
