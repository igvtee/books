#include <stdio.h>

/* print Fahrenheit-Celsius table */

#define LOWER 0		/* lower limit of table */
#define UPPER 300	/* upper limit */
#define STEP 20		/* step size */

float fahr2cels(int fahr)
{
	return (5.0/9.0)*(fahr-32);
}

int main(void)
{
	int fahr;

	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
		printf("%3d %6.1f\n", fahr, fahr2cels(fahr));
	return 0;
}
