#include <stdio.h>

float single_tax(float income)
{
	const float tax[][3] = {
		{23350, 0, .15},
		{56550, 3502.5, .28},
		{117950, 12798.5, .31},
		{256500, 31832.5, .36},
		{0, 81710.5, .396},
	};
	const float (*ptax)[3] = tax;

	while (income > ptax[0][0]) {
		if (ptax[0][0] == 0)
			break;
		ptax++;
		continue;
	}

	if (ptax[0][1] == 0)
		return income * ptax[0][2];
	else
		return ptax[0][1] + (income - (ptax-1)[0][0]) * ptax[0][2];
}

int main(void)
{
	float tax;
	float income = 100.0;

	tax = single_tax(income);
	printf("%.2f: %.2f\n", income, tax);

	return 0;
}
