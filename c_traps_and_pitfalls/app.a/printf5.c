#include <stdio.h>

int main(void)
{
	int i;

	for (i = 0; i <= 10; i++)
		printf("%2d %2d *\n", i, i*i);

	return 0;
}
