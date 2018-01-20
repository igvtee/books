#include <stdio.h>

int main(void)
{
	int a, b, q, r;

	/* q * b + r == a */
	/* a >= 0 && b > 0, |r| < |b| */

	a = 3, b = 2;
	q = a / b;
	r = a % b;
	printf("a: %d, b: %d, q: %d, r: %d\n", a, b, q, r);

	a = -3, b = 2;
	q = a / b;
	r = a % b;
	printf("a: %d, b: %d, q: %d, r: %d\n", a, b, q, r);

	return 0;
}
