#include <stdio.h>

/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n)
{
	int gap, i, j, temp;

	for (gap = n/2; gap > 0; gap /= 2) {
		for (i = gap; i < n; i++) {
			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
			}
		}
	}
}

int main(void)
{
	int v[] = {4, 3, 2, 1, 0};
	int n = sizeof(v) / sizeof(int);
	int i;

	shellsort(v, n);
	for (i = 0; i < n; i++)
		printf("%d ", v[i]);
	putchar('\n');

	return 0;
}
