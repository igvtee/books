#include <stdio.h>
#include <stdarg.h>

/*
 * [0] 1 ~ 10
 * [1],[2] lo/hi of 1
 * [2],[3] lo/hi of 2
 * ...
 */
int array_offset(int arrayinfo[], ...)
{
	va_list ap;
	int ret = -1, i, j, dim;
	int loc[10];

	dim = arrayinfo[0];
	if (dim < 1 || dim > 10) {
		printf("dimension error %d\n", dim);
		goto dimension;
	}

	/* save location */
	va_start(ap, arrayinfo);
	for (i = 0; i < dim; i++)
		loc[i] = va_arg(ap, int);
	va_end(ap);

	/* check lo/hi limit */
	for (i = 1, j = 0; i < dim*2; i+=2, j++) {
		if (arrayinfo[i] > arrayinfo[i+1]) {
			printf("lo/hi limit error %d %d\n",
			       arrayinfo[i], arrayinfo[i+1]);
			goto dimension;
		}
		if (loc[j] < arrayinfo[i]) {
			printf("location %d is less than lo %d\n",
			       loc[j], arrayinfo[i]);
			goto dimension;
		}
		if (loc[j] > arrayinfo[i+1]) {
			printf("location %d is larger than hi %d\n",
			       loc[j], arrayinfo[i+1]);
			goto dimension;
		}
	}

	for (i = 1, j = 0; j < dim; i+=2, j++) {
		if (j == 0)
			ret = loc[j] - arrayinfo[i];
		else
			ret = ret * (arrayinfo[i+1] - arrayinfo[i] + 1)
				+ loc[j] - arrayinfo[i];
	}

dimension:
	return ret;
}

int main(void)
{
	int arrayinfo[] = {3, 4, 6, 1, 5, -3, 3};
	int offset;

	offset = array_offset(arrayinfo, 4, 1, -3);
	printf("%-10s: %d\n", "4, 1, -3", offset);
	offset = array_offset(arrayinfo, 4, 1, -2);
	printf("%-10s: %d\n", "4, 1, -2", offset);
	offset = array_offset(arrayinfo, 4, 1, 3);
	printf("%-10s: %d\n", "4, 1, 3", offset);
	offset = array_offset(arrayinfo, 4, 2, -3);
	printf("%-10s: %d\n", "4, 2, -3", offset);
	offset = array_offset(arrayinfo, 5, 1, -3);
	printf("%-10s: %d\n", "5, 1, -3", offset);
	offset = array_offset(arrayinfo, 6, 3, 1);
	printf("%-10s: %d\n", "6, 3, 1", offset);

	return 0;
}
