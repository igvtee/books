#include "malloc.h"
#include <stdio.h>

int main(void)
{
	char *str;

	str = malloc(100);
	sprintf(str, "hello world!!");
	printf("%s\n", str);
	free(str);

	return 0;
}
