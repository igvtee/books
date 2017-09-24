#include <stdio.h>

int ascii_to_integer(char *string)
{
	int num = 0;

	while (*string != '\0') {
		if (*string < '0' || *string > '9')
			return 0;
		num = (num * 10) + (*string - '0');
		string++;
	}

	return num;
}

int main(void)
{
	int num;
	char *str = "123456";

	num = ascii_to_integer(str);
	printf("%s %d\n", str, num);

	return 0;
}
