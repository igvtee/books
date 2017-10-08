#include <stdio.h>

int identity_matrix(const int (*matrix)[10][10])
{
	const int (*line)[10] = matrix[0];
	int i, cnt;

	cnt = 0;
	while (line < matrix[0] + 10) {
		for (i = 0; i < 10; i++) {
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

	ret = identity_matrix(&matrix);
	printf("is %sidentity matrix\n", ret? "" : "not ");

	return 0;
}
