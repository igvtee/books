#include <stdio.h>
#include <stdlib.h>

int cmpint(const void *x, const void *y)
{
	int a = *(const int *)x;
	int b = *(const int *)y;

	return a - b;
}

int main(void)
{
	int x[3];

	if (scanf("%d%d%d", &x[0], &x[1], &x[2]) != 3)
		return 1;

	qsort(x, 3, sizeof(x[0]), cmpint);

	/* check size */
	if (x[0] + x[1] <= x[2]) {
		printf("triangle size error!\n");
		return 1;
	}

	if (x[0] == x[1] && x[0] == x[2])
		printf("Equilateral triangle\n");
	else if (x[0] != x[1] && x[0] != x[2] &&
		 x[1] != x[2])
		printf("Scalene triangle\n");
	else
		printf("Isosceles triangle\n");

	return 0;
}
