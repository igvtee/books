#include <stdio.h>

int del_substr(char *str, char const *substr)
{
	int ret = 0;
	char const *sub;
	char *dstr;

	while (*str) {
		if (!ret) {
			/* search substr */
			sub = substr;
			while (*sub) {
				if (*str == *sub) {
					str++;
					sub++;
					continue;
				}
				break;
			}

			/* found substr */
			if (*sub == '\0') {
				dstr = str - (sub - substr);
				ret = 1;
			}
		}

		/* copy substr */
		if (ret)
			*dstr++ = *str;
		str++;
	}

	/* terminate */
	if (ret)
		*dstr = '\0';

	return ret;
}

int main(void)
{
	char str[64] = "CDABCDEFG";
	char const *substr1 = "FGH";
	char const *substr2 = "CDE";
	int ret;

	ret = del_substr(str, substr1);
	printf("%s %s\n", str, substr1);

	ret = del_substr(str, substr2);
	printf("%s %s\n", str, substr2);

	return 0;
}
