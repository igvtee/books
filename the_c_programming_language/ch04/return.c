#include <stdio.h>

int ret(int a)
{
	if (a)
		return 123;
}

int main(void)
{
	printf("with return %d\n", ret(1));
	printf("without return %d\n", ret(0));

	return 0;
}
