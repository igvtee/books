#include <stdio.h>

/* strcat: concateenate t to end of s; s must be big enough */
void mystrcat(char *s, char *t)
{
	while (*s)		/* find end of s */
		s++;
	while ((*s++ = *t++))	/* copy t */
		;
}

int main(void)
{
	char str[32] = "world";
	char buf[32] = "hello ";
	char *p = str;

	mystrcat(buf, str);
	printf("%s\n", buf);

	printf("%c\n", ++*p);
	printf("%c\n", *p++);
	printf("%c\n", *p);
	printf("%c\n", *++p);

	return 0;
}
