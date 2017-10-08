#include <stdio.h>

int identity_matrix(const int *matrix, int size)
{
	const int (*line)[size] = (const int (*)[])matrix;
	const int (*end)[size] = line + size;
	int i, cnt;

	cnt = 0;
	while (line < end) {
		for (i = 0; i < size; i++) {
			if (cnt == i && line[0][i] == 1)
				continue;
			else if (line[0][i] == 0)
				continue;
			else
				return 0;
		}
		line++;
		cnt++;
	}
	return 1;
}

int main(void)
{
	int ret;
	int matrix[10][10] = {
		{1},
		{0, 1},
		{0, 0, 1},
		{0, 0, 0, 1},
		{0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	};

	ret = identity_matrix(matrix[0],
			      sizeof(matrix)/sizeof(matrix[0]));
	printf("is %sidentity matrix\n", ret? "" : "not ");

	return 0;
}
