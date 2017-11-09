#include <stdio.h>

int numeric_palindrome(int value)
{
	char buf[32];

	snprintf(buf, sizeof(buf), "%d", value);

	return palindrome(buf);
}
