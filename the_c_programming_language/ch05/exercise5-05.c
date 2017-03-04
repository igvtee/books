#include <stdio.h>
#include <string.h>

/* strncpy: copy n characters from t to s */
void mystrncpy(char *s, const char *t, int n)
{
	while (*t && n-- > 0)
		*s++ = *t++;
	while (n-- > 0)
		*s++ = '\0';
}

/* strncat: concatenate n characters of t to the end of s */
void mystrncat(char *s, const char *t, int n)
{
	mystrncpy(s + strlen(s), t, n);
}

/* strncmp: compare at most n characters of t with s */
int mystrncmp(const char *s, const char *t, int n)
{
	for (; *s == *t; s++, t++)
		if (*s == '\0' || --n <= 0)
			return 0;
	return *s - *t;
}

int main(void)
{
	char data[16];
	const char *str = "hello";

	mystrncpy(data, str, sizeof(data));
	printf("%s\n", data);
	mystrncat(data, str, sizeof(data));
	printf("%s\n", data);
	if (mystrncmp(data, str, strlen(str)))
		printf("the same\n");
	else
		printf("not the same\n");

	return 0;
}
