#include <stdio.h>

int f(int a, int b, int c)
{
	return a + b + c;
}

int main(void)
{
	int a, t, c;
	int ret;

	a = c = 1;
	ret = f(a, (t=3, t+2), c);
	printf("ret: %d\n", ret);

	return 0;
};
