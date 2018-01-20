#include <stdio.h>

int main(void)
{
	char name[14] = "filename.txt";

	printf("'%.14s'\n", name);
	printf("'%14.14s'\n", name);
	printf("'%-14s'\n", name);

	return 0;
}
