#include <stdio.h>

extern int *a;
extern int b[];

int main(void)
{
	int x, y;

	x = a[3];
	y = b[3];

	printf("x: %d, y: %d\n", x, y);

	return 0;
}
