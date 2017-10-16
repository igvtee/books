#include <stdio.h>

int main(void)
{
	union {
		int a;
		float b;
		char c;
	} x;

	x.a = 25;
	x.b = 3.14;
	x.c = 'x';

	printf("%d %g %c\n", x.a, x.b, x.c);

	return 0;
}
