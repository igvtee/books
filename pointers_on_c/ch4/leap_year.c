#include <stdio.h>

int main(void)
{
	int year;
	int leap_year;

	if (scanf("%d", &year) != 1)
		return 1;

	leap_year = !(year % 4);
	if (leap_year) {
		leap_year = year % 100;
		if (!leap_year)
			leap_year = !(year % 400);
	}

	printf("%d is %sleap year.\n", year,
	      leap_year? "" : "not ");

	return 0;
}
