#include <stdio.h>

int main(void)
{
	int test[5];
	int *p = test, *q = &test[3];

	printf("%ld\n", q - p + 1);

	return 0;
}
