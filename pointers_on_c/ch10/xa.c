#include <stdio.h>

int main(void)
{
	struct {
		int a:2;
	} x;

	x.a = 1;
	x.a += 1;
	printf("%d\n", x.a);

	return 0;
}
