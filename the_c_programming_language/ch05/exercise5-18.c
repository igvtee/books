#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN	100

enum { NAME, PARENS, BRACKETS };
enum { NO, YES };

void dcl(void);
void dirdcl(void);
void errmsg(char *);
int gettoken(void);
int tokentype;			/* type of last token */
char token[MAXTOKEN];		/* last token string */
char name[MAXTOKEN];		/* identifier name */
char datatype[MAXTOKEN];	/* data type = char, int, etc. */
char out[1000];			/* output string */

extern int prevtoken;		/* there is no previous token */

int main(void)		/* convert declaration to words */
{
	while (gettoken() != EOF) {		/* 1st token on line */
		strcpy(datatype, token);	/* is the datatype */
		out[0] = '\0';
		dcl();		/* parse rest of line */
		if (tokentype != '\n')
			printf("syntax error\n");
		printf("%s: %s %s\n", name, out, datatype);
	}
	return 0;
}

/* dcl: parse a declarator */
void dcl(void)
{
	int ns;

	for (ns = 0; gettoken() == '*'; )	/* count *'s */
		ns++;
	dirdcl();
	while (ns-- > 0)
		strcat(out, " pointer to");
}

/* dirdcl: parse a direct declarator */
void dirdcl(void)
{
	int type;

	if (tokentype == '(') {			/* ( dcl ) */
		dcl();
		if (tokentype != ')')
			errmsg("error: missing )\n");
	} else if (tokentype == NAME)		/* variable name */
		strcpy(name, token);
	else
		errmsg("error: expected name or (dcl)\n");
	while ((type = gettoken()) == PARENS || type == BRACKETS)
		if (type == PARENS)
			strcat(out, " function returning");
		else {
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
}

/* errmsg: print error message and indicate avail. token */
void errmsg(char *msg)
{
	printf("%s", msg);
	prevtoken = YES;
}
