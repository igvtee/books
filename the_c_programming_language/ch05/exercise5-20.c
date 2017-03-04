/*
 * dcl:		optional *'s direct-dcl
 *
 * direct-dcl:	name
 *		(dcl)
 *		direct-dcl(optional parm-dcl)
 *		direct-dcl[optional size]
 *
 * parm-dcl:	parm-dcl, dcl-spec dcl
 *
 * dcl-spec:	type-spec dcl-spec
 *		type-qual dcl-spec
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXTOKEN	100

enum { NAME, PARENS, BRACKETS };
enum { NO, YES };

void dcl(void);
void dirdcl(void);
void errmsg(char *);
int gettoken(void);
void parmdcl(void);
void dclspec(void);
int typespec(void);
int typequal(void);
int compare(const void *s, const void *t);

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
	} else if (tokentype == NAME) {		/* variable name */
		if (name[0] == '\0')
			strcpy(name, token);
	} else
		prevtoken = YES;
	while ((type = gettoken()) == PARENS || type == BRACKETS ||
	       type == '(')
		if (type == PARENS)
			strcat(out, " function returning");
		else if (type == '(') {
			strcat(out, " function expecting");
			parmdcl();
			strcat(out, " and returning");
		} else {
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

/* parmdcl: parse a parameter declarator */
void parmdcl(void)
{
	do {
		dclspec();
	} while (tokentype == ',');
	if (tokentype != ')')
		errmsg("missing ) in parameter declaration\n");
}

/* dclspec: declaration specification */
void dclspec(void)
{
	char temp[MAXTOKEN];

	temp[0] = '\0';
	gettoken();
	do {
		if (tokentype != NAME) {
			prevtoken = YES;
			dcl();
		} else if (typespec() == YES) {
			strcat(temp, " ");
			strcat(temp, token);
			gettoken();
		} else if (typequal() == YES) {
			strcat(temp, " ");
			strcat(temp, token);
			gettoken();
		} else
			errmsg("unknown type in parameter list\n");
	} while (tokentype != ',' && tokentype != ')');
	strcat(out, temp);
	if (tokentype == ',')
		strcat(out, ",");
}

/* typespec: return YES if token is a type-specifier */
int typespec(void)
{
	static char *types[] = { "char", "int", "void" };
	char *pt = token;

	if (bsearch(&pt, types, sizeof(types)/sizeof(*types),
		    sizeof(*types), compare) == NULL)
		return NO;
	else
		return YES;
}

/* typequal: return YES if token is a type-qualifer */
int typequal(void)
{
	static char *types[] = { "const", "volatile", "register" };
	char *pt = token;

	if (bsearch(&pt, types, sizeof(types)/sizeof(*types),
		    sizeof(*types), compare) == NULL)
		return NO;
	else
		return YES;
}

/* compare: compare two strings for bsearch */
int compare(const void *s, const void *t)
{
	return strcmp(*(const char **)s, *(const char **)t);
}
