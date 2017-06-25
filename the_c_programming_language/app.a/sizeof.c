#include <stdio.h>

int main(void)
{
	short int a = 1;

	/* unary plus operator cause integral promotion */
	printf("%zu %zu\n", sizeof a, sizeof +a);

	return 0;
}
