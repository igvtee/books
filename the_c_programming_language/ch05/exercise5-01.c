#include <stdio.h>
#include <ctype.h>

#define SIZE	4

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
	int c, d, sign;

	while (isspace(c = getch()))		/* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		d = c;				/* remember sign char */
		if (!isdigit(c = getch())) {
			if (c != EOF)
				ungetch(c);	/* push back non-digit */
			ungetch(d);		/* push back sign char */
			return d;
		}
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

int main(void)
{
	int num, ret;

	while ((ret = getint(&num)) != EOF) {
		if (isdigit(ret) || ret == '\n')
			printf("getint: %d\n", num);
		else
			getch();
	}

	return 0;
}
