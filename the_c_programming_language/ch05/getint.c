#include <stdio.h>
#include <ctype.h>

#define SIZE	4

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch()))	/* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

int main(void)
{
	int n, array[SIZE];

	n = 0;
	while (n < SIZE)
		array[n++] = 0;
	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
		;
	n = 0;
	while (n < SIZE) {
		printf("%d: %d\n", n, array[n]);
		n++;
	}

	return 0;
}
