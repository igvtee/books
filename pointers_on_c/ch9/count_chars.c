#include <stdio.h>

int count_chars(char const *str, char const *chars)
{
	int cnt = 0;
	const char *ch;

	while (*str) {
		ch = chars;
		while (*ch) {
			if (*str == *ch) {
				cnt++;
				break;
			}
			ch++;
		}
		str++;
	}

	return cnt;
}

int main(void)
{
	char str[] = "this is an example string";
	char chars[] = "aeiou";
	int cnt;

	cnt = count_chars(str, chars);
	printf("%s. %s. %d\n", str, chars, cnt);

	return 0;
}
