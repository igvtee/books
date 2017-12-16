#include <stdio.h>

int main(void)
{
	char c;

	printf("'A'\t%zu \n", sizeof 'A');
	printf("char\t%zu \n", sizeof(char));
	printf("c\t%zu \n", sizeof(c));

	return 0;
}
