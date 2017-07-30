#include <stdio.h>

static float mysqrt(int n, float a)
{
	float a1 = (a + n/a) / 2;
	if (a == a1)
		return a;
	else
		return mysqrt(n, a1);
}

int main(void)
{
	int a;

	if (scanf("%d", &a) != 1)
		return 1;
	printf("%d sqrt is %f\n", a, mysqrt(a, 1));

	return 0;
}
