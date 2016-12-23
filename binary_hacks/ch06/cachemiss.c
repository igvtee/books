#include <stdlib.h>

#define NUM 10000

int cache_miss(void)
{
	int *a[NUM];
	int i, j, sum;

	for (i = 0; i < NUM; i++)
		a[i] = (int *)malloc(sizeof(int) * NUM);
	for (i = 0; i < NUM; i++)
		for (j = 0; j < NUM; j++) {
//			sum += a[i][j];
			sum += a[j][i];
		}

	return sum;
}

int main(void)
{
	cache_miss();
	return 0;
}
