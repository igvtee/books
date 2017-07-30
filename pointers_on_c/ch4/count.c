#include <stdio.h>

int math(int x)
{
	return 3 * x * x - 4 * x + 6;
}

int main(void)
{
	printf("%d\n", math(1));

	return 0;
}
