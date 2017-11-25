#include <stdio.h>
#include <math.h>
#include <float.h>

int main(void)
{
	double x;

	x = sqrt(-5);
	if (isnan(x))
		perror("sqrt: ");
	else
		printf("%f\n", x);

	x = exp(DBL_MAX);
	if (x == HUGE_VAL)
		perror("exp: ");

	return 0;
}
