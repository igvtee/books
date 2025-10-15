#include <stdio.h>

void bubble_sort(int a[], int n)
{
	int i = 0, j = 0, tmp;

	for (i = 0; i <= n; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

int main(int argc, char *argv[])
{
	int arr[10] = {64, 34, 25, 12, 22, 11, 90, 45, 86, 23};

	bubble_sort(arr, sizeof(arr));
	for (int i = 0; i <= sizeof(arr); i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
