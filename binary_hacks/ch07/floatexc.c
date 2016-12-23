#define _GNU_SOURCE
#include <fenv.h>
#include <stdio.h>

int main(void)
{
	double a;

#if 0
	int excepts = fegetexcept();
	excepts |= FE_INVALID | FE_DIVBYZERO | FE_OVERFLOW;
	feenableexcept(excepts);
#endif
	a = 1.0 / 0.0;

	printf("%f\n", a);
	return 0;
}
