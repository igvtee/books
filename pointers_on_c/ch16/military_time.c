#include <stdio.h>
#include <time.h>

int main(void)
{
	struct tm *tm;
	time_t now;

	now = time(NULL);
	tm = localtime(&now);
	printf("%d:%02d:%02d %d/%02d/%02d\n",
			tm->tm_hour, tm->tm_min, tm->tm_sec,
			tm->tm_mon + 1, tm->tm_mday,
			tm->tm_year + 1900);

	return 0;
}
