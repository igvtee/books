#include <stdio.h>

int gcd(int m, int n)
{
	int r = m % n;
	if (r == 0)
		return n;
	else
		return gcd(n, r);
}

int main(void)
{
	printf("gcd(100, 20) = %d\n", gcd(100, 20));

	return 0;
}
