#include <stdio.h>

int main(void)
{
	char *comment = /*/**/"*/"/*"/**/;
	printf("%s\n", comment);

	return 0;
}
