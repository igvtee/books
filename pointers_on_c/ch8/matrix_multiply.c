#include <stdio.h>

/*
 * m1 is x,y
 * m2 is y,z
 * r  is x,z
 */
void matrix_multiply(int *m1, int *m2, int *r, int x, int y, int z)
{
	int i, j, k;

	for (i = 0; i < x; i++) {
		for (k = 0; k < z; k++) {
			*r = 0;
			for (j = 0; j < y; j++) {
				*r += *(m1+j+(i*y)) * *(m2+k+(j*z));
			}
			r++;
		}
	}
}

void matrix_print(int *m, int x, int y)
{
	int i, j;

	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++) {
			printf("%d ", *m);
			m++;
		}
		putchar('\n');
	}
}

int main(void)
{
	int x = 3, y = 2, z = 4;
	int m1[3][2] = {
		{2, -6},
		{3, 5},
		{1, -1},
	};
	int m2[2][4] = {
		{4, -2, -4, -5},
		{-7, -3, 6, 7},
	};
	int r[3][4];

	matrix_multiply(m1[0], m2[0], r[0], x, y, z);
	matrix_print(m1[0], x, y);
	matrix_print(m2[0], y, z);
	matrix_print(r[0], x, z);

	return 0;
}
