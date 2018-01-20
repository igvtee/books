#include <stdio.h>

int main(void)
{
	int i;
	double x;

	for (i = -3; i <= 3; i++)
		printf("% d\n", i);

	for (x = -3; x <= 3; x++)
		printf("% e %+e %e\n", x, x, x);

	return 0;
}
