#include <stdio.h>

const char *my_strnchr(char const *str, int ch, int which)
{
	const char *found = NULL;

	if (which < 1)
		return NULL;

	while (*str) {
		if (*str == ch) {
			if (--which == 0) {
				found = str;
				break;
			}
		}
		str++;
	}

	return found;
}

int main(void)
{
	char str[] = "0123456U89Ubcdef";
	const char *end;

	end = my_strnchr(str, 'U', 2);
	if (end)
		printf("%s. offset: %td\n", str, end-str);

	return 0;
}
