/*
 * Give the current time as a young child would.
 */
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	time_t now;
	struct tm *tm;
	int hour;
	int minute;

	/*
	 * Get current hour and minute.
	 */
	now = time(NULL);
	tm = localtime(&now);
	hour = tm->tm_hour;
	minute = tm->tm_min;

	/*
	 * Round and normalize the hour, convert the minute, and then print them.
	 */
	if (minute >= 30)
		hour += 1;
	hour %= 12;
	if (hour == 0)
		hour = 12;
	minute += 2;
	minute /= 5;
	if (minute == 0)
		minute = 12;

	printf("The big hand is on the %d, and the little hand is on the %d.\n",
			minute, hour);
	return EXIT_SUCCESS;
}
