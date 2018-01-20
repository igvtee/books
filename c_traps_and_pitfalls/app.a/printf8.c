#include <stdio.h>
#include <math.h>

int main(void)
{
	double pi;

	pi = 4 * atan(1.0);
	printf("%.0f %.1f %.2f %.3f %.6f %.10f\n",
			pi, pi, pi, pi, pi, pi);
	printf("%.0e %.1e %.2e %.10e\n",
			pi, pi, pi, pi);

	return 0;
}
