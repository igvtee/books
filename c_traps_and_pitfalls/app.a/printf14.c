#include <stdio.h>

int main(void)
{
	int n;

	printf("%p\n", &n);
	printf("hello\n%n", &n);
	printf("%d\n", n);

	return 0;
}
