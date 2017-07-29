#include <stdio.h>

int main(void)
{
	char *data = "Hello world!";

	printf("%s\n", data);
	data[0] = 'h';
	printf("%s\n", data);

	return 0;
}
