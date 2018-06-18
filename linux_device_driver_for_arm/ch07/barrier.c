#include <stdio.h>

int main(void)
{
	int a = 0, b, c, d[4096], e;

	e = d[4095];
	b = a;
	c = a;

	printf("a:%d b:%d c:%d e:%d\n", a, b, c, e);

	return 0;
}
