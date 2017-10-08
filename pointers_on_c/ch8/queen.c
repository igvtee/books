#include <stdio.h>
#include <string.h>

#define MATRIX_SIZE 8
int count;

void print_matrix(int (*mat)[MATRIX_SIZE][MATRIX_SIZE])
{
	int i, j;

	for (i = 0; i < MATRIX_SIZE; i++) {
		for (j = 0; j < MATRIX_SIZE; j++)
			if ((*mat)[i][j] == 1)
				putchar('Q');
			else
				putchar('_');
		putchar('\n');
	}
	putchar('\n');
	count++;
}

int check_matrix(int (*mat)[MATRIX_SIZE][MATRIX_SIZE], int x, int y)
{
	int i, j;

	for (i = 0; i < MATRIX_SIZE; i++)
		if ((*mat)[x][i] == 1)
			return 1;
	for (i = 0; i < MATRIX_SIZE; i++)
		if ((*mat)[i][y] == 1)
			return 1;
	i = x, j =y;
	while (--i >= 0 && --j >= 0)
		if ((*mat)[i][j] == 1)
			return 1;
	i = x, j =y;
	while (++i < MATRIX_SIZE && --j >= 0)
		if ((*mat)[i][j] == 1)
			return 1;
	i = x, j =y;
	while (++i < MATRIX_SIZE && ++j < MATRIX_SIZE)
		if ((*mat)[i][j] == 1)
			return 1;
	i = x, j =y;
	while (--i >= 0 && ++j < MATRIX_SIZE)
		if ((*mat)[i][j] == 1)
			return 1;
	return 0;
}

void set_matrix(int (*mat)[MATRIX_SIZE][MATRIX_SIZE], int x)
{
	int j;

	for (j = 0; j < MATRIX_SIZE; j++) {
		if (check_matrix(mat, x, j))
			continue;
		(*mat)[x][j] = 1;
		if (x == MATRIX_SIZE-1)
			print_matrix(mat);
		else
			set_matrix(mat, x+1);
		(*mat)[x][j] = 0;
	}
}

int main(void)
{
	int matrix[MATRIX_SIZE][MATRIX_SIZE];

	memset((void *)matrix, 0, sizeof(matrix));
	set_matrix(&matrix, 0);
	printf("total %d solutions\n", count);

	return 0;
}
