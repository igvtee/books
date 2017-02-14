#include <stdio.h>

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(int v[], int left, int right)
{
	int i, last;
	void swap(int v[], int i, int j);

	if (left >= right)	/* do nothing if array contains */
		return;	/* fewer than two elements */
	swap(v, left, (left + right)/2);	/* move partition elem */
	last = left;	/* to v[0] */
	for (i = left+1; i <= right; i++)	/* partition */
		if (v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last);	/* restore partition elem */
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int main(void)
{
	int i;
	int v[] = {6, 5, 4, 3, 2, 1};
	int size = sizeof(v)/sizeof(v[0]);

	qsort(v, 0, size-1);
	for (i = 0; i < size; i++)
		printf("%d ", v[i]);
	putchar('\n');

	return 0;
}
