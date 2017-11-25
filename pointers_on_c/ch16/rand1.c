#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;

	for (i = 0; i < 100; i++)
		printf("%d\n", rand() % 2);

	return 0;
}
