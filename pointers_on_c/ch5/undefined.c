#include <stdio.h>

int main(void)
{
	int i = 10;

	i = i-- - --i * (i = -3) * i++ + ++i;
	printf("i = %d\n", i);

	return 0;
}
