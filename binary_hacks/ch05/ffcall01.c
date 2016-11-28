#include <avcall.h>
#include <stdio.h>

char nth(const char *str, int i)
{
	return str[i - 1];
}

int main(void)
{
	int n = 5;
	const char *msg = "binary";
	char ret;
	av_alist alist;

	printf("NORMAL: %c\n", nth(msg, n));

	av_start_char(alist, &nth, &ret);
	av_ptr(alist, const char *, msg);
	av_int(alist, n);
	av_call(alist);

	printf("FFCALL: %c\n", ret);

	return 0;
}
