#include <stdio.h>
#include <stdlib.h>	/* for atof */

#define MAXOP	100	/* max size of operand or operator */
#define NUMBER	'0'	/* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

/* reverse Polish calculator */
main()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command '%s'\n", s);
			break;
		}
	}
	return 0;
}

#define MAXVAL	100	/* maximum depth of vval stack */

int sp = 0;	/* next free stack position */
double val[MAXVAL];	/* value stack */

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value form stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

#include <ctype.h>

#define MAXLINE	100

int li = 0;	/* input line index */
char *line = NULL;	/* one input line */
size_t lsize = 0;	/* line size */
size_t rsize;		/* read size */

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, c;

	if (line == NULL || rsize == li) {
		if ((rsize = getline(&line, &lsize, stdin)) == -1) {
			if (line) {
				free(line);
				line = NULL;
			}
			return EOF;
		}
		li = 0;
	}
	while ((s[0] = c = line[li++]) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;	/* not a number */
	i = 0;
	if (isdigit(c))	/* collect integer part */
		while (isdigit(s[++i] = c = line[li++]))
			;
	if (c == '.')	/* collect fraction part */
		while (isdigit(s[++i] = c = line[li++]))
			;
	s[i] = '\0';
	li--;
	return NUMBER;
}
