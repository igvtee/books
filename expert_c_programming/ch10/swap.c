#include <stdio.h>

void swap(int *a, int *b)
{
	/* fix */
	//if (a == b)
	//	return;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

int main(void)
{
	int a, b;

	a = 3;
	b = 4;
	printf("a = %d, b = %d swap to ", a, b);
	swap(&a, &b);
	printf("a = %d, b = %d\n", a, b);

	printf("a = %d, a = %d swap to ", a, a);
	swap(&a, &a);
	printf("a = %d, a = %d\n", a, a);

	return 0;
}
