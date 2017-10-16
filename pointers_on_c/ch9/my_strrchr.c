#include <stdio.h>

const char *my_strrchr(char const *str, int ch)
{
	const char *found = NULL;

	while (*str) {
		if (*str == ch)
			found = str;
		str++;
	}

	return found;
}

int main(void)
{
	char str[] = "0123456U89Ubcdef";
	const char *end;

	end = my_strrchr(str, 'U');
	if (end)
		printf("%s. offset: %td\n", str, end-str);

	return 0;
}
