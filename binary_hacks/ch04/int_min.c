#include <stdio.h>
#include <limits.h>

int main(void)
{
	volatile int a = -1;
	printf("%d\n", INT_MIN / a);
	return 0;
}
