#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	div_t result = div(-5, 3);

	printf("abs(-3) = %d\n", abs(-3));
	printf("div(-5, 3) quot:%d, rem:%d\n", result.quot,
			result.rem);
	printf("-5/3: %d\n", -5/3);
	printf("-5%%3: %d\n", -5%3);

	return 0;
}
