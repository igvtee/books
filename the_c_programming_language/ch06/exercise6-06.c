#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "nlist.h"

#define MAXWORD	100

void error(int, char *);
int getch(void);
void getdef(void);
int getword(char *, int);
void skipblanks(void);
void ungetch(int);
void ungets(char *);

/* simple version of #define processor */
int main(void)
{
	char w[MAXWORD];
	struct nlist *p;

	while (getword(w, MAXWORD) != EOF)
		if (strcmp(w, "#") == 0)	/* beginning of direct. */
			getdef();
		else if (!isalpha(w[0]))
			printf("%s", w);	/* cannot be defined */
		else if ((p = lookup(w)) == NULL)
			printf("%s", w);	/* not defined */
		else
			ungets(p->defn);	/* push definition */
	return 0;
}

/* getdef: get definition and install it */
void getdef(void)
{
	int i;
	char def[MAXWORD], dir[MAXWORD], name[MAXWORD];

	skipblanks();
	if (!isalpha(getword(dir, MAXWORD)))
		error(dir[0], "getdef: expecting a directive after #");
	else if (strcmp(dir, "define") == 0) {
		skipblanks();
		if (!isalpha(getword(name, MAXWORD)))
			error(name[0], "getdef: non-alpha - name expected");
		else {
			skipblanks();
			for (i = 0; i < MAXWORD-1; i++)
				if ((def[i] = getch()) == EOF ||
				    def[i] == '\n')
					break;	/* end of definition */
			def[i] = '\0';
			if (i <= 0)	/* no definition ? */
				error('\n', "getdef: incomplete define");
			else
				install(name, def);
		}
	} else if (strcmp(dir, "undef") == 0) {
		skipblanks();
		if (!isalpha(getword(name, MAXWORD)))
			error(name[0], "getdef: non-alpha in undef");
		else
			undef(name);
	} else
		error(dir[0], "getdef: expecting a directive after #");
}

/* error: print error message and skip the rest of the line */
void error(int c, char *s)
{
	printf("error: %s\n", s);
	while (c != EOF && c != '\n')
		c = getch();
}

/* skipblanks: skip blank and tab characters */
void skipblanks(void)
{
	int c;

	while ((c = getch()) == ' ' || c == '\t')
		;
	ungetch(c);
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	if ((c = getch()) != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}
