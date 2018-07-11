#include <stdio.h>

int main (void)
{
	int i, sum;

	for (i = 1, sum = 0; i <= 10; i++)
	{
		sum += i;
#ifdef DEBUG
		printf ("sum += %d is %d\n", i, sum);
#endif
	}
	printf ("total sum is %d\n", sum);

	return 0;
}
