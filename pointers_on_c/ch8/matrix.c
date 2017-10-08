#include <stdio.h>

int main(void)
{
	int matrix[6][10];
	int *mp;

	matrix[3][8] = 38;
	matrix[3][9] = 39;
	matrix[4][0] = 40;

	mp = &matrix[3][8];
	printf("First value is %d\n", *mp);
	printf("Second value is %d\n", *++mp);
	printf("Third value is %d\n", *++mp);

	return 0;
}
