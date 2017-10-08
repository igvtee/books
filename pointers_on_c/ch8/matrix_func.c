#include <stdio.h>

void func1(int (*mat)[10])
{
}

void func2(int mat[][10])
{
}

void func3(int **mat)
{
}

int main(void)
{
	int matrix[3][10];

	func1(matrix);
	func2(matrix);

	/* wrong */
	func3(matrix);

	return 0;
}
