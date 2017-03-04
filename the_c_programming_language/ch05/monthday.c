#include <stdio.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
	int i, leap;

	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;

	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}

char f1(char daytab[2][13])
{
	return daytab[0][1];
}

char f2(char daytab[][13])
{
	return daytab[0][2];
}

char f3(char (*daytab)[13])
{
	return daytab[0][3];
}

/* month_name: return name of n-th month */
char *month_name(int n)
{
	static char *name[] = {
		"Illegal month",
		"January", "February", "March",
		"April", "May", "June",
		"July", "August", "September",
		"October", "November", "December"
	};

	return (n < 1 || n > 12) ? name[0] : name[n];
}

int main(void)
{
	int m, d;

	month_day(1988, 60, &m, &d);
	printf("1988 60 => month %d, day %d\n", m, d);
	printf("1988 %d %d => days %d\n", m, d,
	       day_of_year(1988, m, d));
	printf("%d %d %d\n", f1(daytab), f2(daytab), f3(daytab));
	printf("%s\n", month_name(0));

	return 0;
}
