/*
 * Compute the monthly mortgage payment given the loan amount, annual interest
 * rate, and loan term.
 */
#include <math.h>

double payment(double amount, double interest, int periods)
{
	interest /= 1200;
	periods *= 12;
	amount = amount * interest /
		(1 - pow(1 + interest, (double)(-periods)));

	return floor(amount * 100 + 0.5) / 100;
}
