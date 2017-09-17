#include <stdio.h>

void reverse_string(char *string)
{
	char *end = string;
	char ch;

	/* find string end */
	while (*end)
		end++;

	end--;
	while (end > string) {
		ch = *string;
		*string++ = *end;
		*end-- = ch;
	}
}

int main(void)
{
	char string[64] = "abcdefghijk";

	printf("%s\n", string);
	reverse_string(string);
	printf("%s\n", string);

	return 0;
}
