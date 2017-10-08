#include <stdio.h>

int main(void)
{
	int vector[10], *vp = vector;
	int matrix[3][10];
	int (*mp)[10] = matrix;

	/* pi == pi2 */
	int *pi = &matrix[0][0];
	int *pi2 = matrix[0];

	return 0;
}
