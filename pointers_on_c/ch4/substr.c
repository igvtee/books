#include <stdio.h>

int substr(char dst[], char src[], int start, int len)
{
	int cnt = 0;

	*dst = '\0';
	if (start < 0 || len < 0)
		return cnt;

	while (*src && (start-- > 0))
		src++;
	if (start > 0)
		return cnt;

	while (*src && (len-- > 0)) {
		*dst++ = *src++;
		cnt++;
	}
	*dst = '\0';

	return cnt;
}

int main(void)
{
	char *src = "Hello world!";
	char dst[5];
	int cnt;

	cnt = substr(dst, src, 5, sizeof(dst) - 1);

	printf("%s\n%d: '%s'\n", src, cnt, dst);

	return 0;
}
