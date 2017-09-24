#include <stdio.h>

long factorial_recursive(int n)
{
	if (n <= 0)
		return 1;
	else
		return n * factorial(n-1);
}

long factorial_loop(int n)
{
	int result = 1;

	while (n > 1) {
		result *= n;
		n -= 1;
	}

	return result;
}
