#include <stdio.h>

int main(void)
{
	char ch = 'a';
	int tmp = 0;
	char *cp = &ch;

	printf("&ch - rvalue: %p, lvalue: INVALIDE\n", &ch);
	printf("cp - rvalue: %p, lvalue: %p\n", (void *)cp, &cp);
	printf("&cp - rvalue: %p, lvalue: INVALIDE\n", &cp);
	printf("*cp - rvalue: %c, lvalue: %p\n", *cp, &*cp);
	printf("*cp + 1 - rvalue: %c, lvalue: INVALIDE\n", *cp + 1);
	printf("*(cp + 1) - rvalue: %c, lvalue: %p\n",
	       *(cp + 1), &*(cp + 1));
	printf("++cp - rvalue: %p, lvalue: INVALIDE\n", ++cp);
	cp = &ch;
	printf("cp++ - rvalue: %p, lvalue: INVALIDE\n", cp++);
	cp = &ch;
	printf("*++cp - rvalue: %c, lvalue: %p\n", *++cp, &*++cp);
	cp = &ch;
	printf("*cp++ - rvalue: %c, lvalue: %p\n", *cp++, &*cp++);
	cp = &ch;
	printf("++*cp - rvalue: %c, lvalue: INVALIDE\n", ++*cp);
	printf("(*cp)++ - rvalue: %c, lvalue: INVALIDE\n", (*cp)++);
	ch = 'a';
	printf("++*++cp - rvalue: %c, lvalue: INVALIDE\n", ++*++cp);
	cp = &ch;
	printf("++*cp++ - rvalue: %c, lvalue: INVALIDE\n", ++*cp++);

	return 0;
}
