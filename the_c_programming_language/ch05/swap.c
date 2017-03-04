#include <stdio.h>

/* interchange *px and *py */
void swap(int *px, int *py)
{
	int temp;

	temp = *px;
	*px = *py;
	*py = temp;
}

int main(void)
{
	int x = 3, y = 4;

	swap(&x, &y);
	printf("x: %d, y: %d\n", x, y);

	return 0;
}
