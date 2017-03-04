#include <stdio.h>

#define MAXLINE	100	/* maximum line size */
#define TABINC	8	/* default tab increment size */
#define YES	1
#define NO	0

void settab(int argc, char *argv[], char *tab);
void detab(char *tab);
int tabpos(int pos, char *tab);

/* replace tabs with blanks */
int main(int argc, char *argv[])
{
	char tab[MAXLINE+1];

	settab(argc, argv, tab);	/* initialize tab stops */
	detab(tab);			/* replace tab w blanks */
	return 0;
}

/* detab: replace tab with blanks */
void detab(char *tab)
{
	int c, pos = 1;

	while ((c = getchar()) != EOF)
		if (c == '\t') {	/* newline character */
			do
				putchar(' ');
			while (tabpos(pos++, tab) != YES);
		} else if (c == '\n') {
			putchar(c);
			pos = 1;
		} else {		/* all other characters */
			putchar(c);
			++pos;
		}
}
