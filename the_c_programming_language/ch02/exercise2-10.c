#include <stdio.h>

/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
	return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}

int main(void)
{
	printf("%c\n", lower('T'));
	return 0;
}
