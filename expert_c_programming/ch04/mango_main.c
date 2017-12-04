#include <stdio.h>

/*
 * error should be
 * extern int mango[];
 */
extern int *mango;

int main(void)
{
	int i;

	for (i = 0; i < 100; i++)
		mango[i] = i;

	for (i = 0; i < 100; i++)
		printf("%d ", mango[i]);
	putchar('\n');

	return 0;
}
