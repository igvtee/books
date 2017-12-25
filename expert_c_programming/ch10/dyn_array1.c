#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int size;
	char *dynamic;
	char input[10];

	printf("Please enter size of array: ");
	size = atoi(fgets(input, 7, stdin));
	dynamic = (char *) malloc(size);
	dynamic[0] = 'a';
	dynamic[size-1] = 'z';

	return 0;
}
