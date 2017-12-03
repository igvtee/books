#include <stdio.h>

int main(void)
{
	int apple;
	int p = 3;

	apple = sizeof (int) * p;
	printf("sizeof apple: %d\n", apple);

	return 0;
}
