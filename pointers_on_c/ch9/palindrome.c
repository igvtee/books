#include <stdio.h>
#include <ctype.h>
#include <string.h>

int palindrome(char *string)
{
	int ret = 0;
	char *end = string + strlen(string) - 1;

	while (string < end) {
		if (!isalpha(*string)) {
			string++;
			continue;
		}
		if (!isalpha(*end)) {
			end--;
			continue;
		}
		if (tolower(*string) != tolower(*end)) {
			ret = -1;
			break;
		}
		string++;
		end--;
	}

	return ret;
}

int main(void)
{
	char str[] = "Mada&$m";
	int ret;

	ret = palindrome(str);
	printf("%s is %spalindrome\n", str, ret? "not " : "");

	return 0;
}
