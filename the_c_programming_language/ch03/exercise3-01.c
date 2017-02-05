#include <stdio.h>
#include <time.h>

#define MAX_ELEMENT 20000

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else	/* found match */
			return mid;
	}
	return -1;	/* no match */
}

int binsearch2(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	mid = (low + high) / 2;
	while (low <= high && x != v[mid]) {
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
		mid = (low + high) / 2;
	}
	if (x == v[mid])
		return low;	/* found match */
	else
		return -1;	/* no match */
}

int main(void)
{
	int testdata[MAX_ELEMENT];
	int index;	/*  Index of found element in test data  */
	int n = -1;	/*  Element to search for  */
	int i;
	clock_t time_taken;

	/*  Initialize test data  */
	for ( i = 0; i < MAX_ELEMENT; ++i )
		testdata[i] = i;

	/* Output approximation of time taken for
	 * 100,000 iterations of binsearch()
	 */
	for ( i = 0, time_taken = clock(); i < 100000; ++i ) {
		index = binsearch(n, testdata, MAX_ELEMENT);
	}
	time_taken = clock() - time_taken;

	if ( index < 0 )
		printf("Element %d not found.\n", n);
	else
		printf("Element %d found at index %d.\n", n, index);

	printf("binsearch() took %lu clocks (%lu seconds)\n",
			(unsigned long) time_taken,
			(unsigned long) time_taken / CLOCKS_PER_SEC);

	/* Output approximation of time taken for
	 * 100,000 iterations of binsearch2()
	 */
	for ( i = 0, time_taken = clock(); i < 100000; ++i ) {
		index = binsearch2(n, testdata, MAX_ELEMENT);
	}
	time_taken = clock() - time_taken;

	if ( index < 0 )
		printf("Element %d not found.\n", n);
	else
		printf("Element %d found at index %d.\n", n, index);

	printf("binsearch2() took %lu clocks (%lu seconds)\n",
			(unsigned long) time_taken,
			(unsigned long) time_taken / CLOCKS_PER_SEC);

	return 0;
}
