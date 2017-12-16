#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXTOKENS 100
#define MAXTOKENLEN 64

enum type_tag { IDENTIFIER, QUALIFIER, TYPE };

struct token {
	char type;
	char string[MAXTOKENLEN];
};

int top = -1;
struct token stack[MAXTOKENS];
struct token this;

#define pop stack[top--]
#define push(s) stack[++top] = s

/* figure out the identifier type */
enum type_tag classify_string(void)
{
	char *s = this.string;

	if (!strcmp(s, "const")) {
		strcpy(s, "read-only");
		return QUALIFIER;
	}
	if (!strcmp(s, "volatile"))
		return QUALIFIER;
	if (!strcmp(s, "void"))
		return TYPE;
	if (!strcmp(s, "char"))
		return TYPE;
	if (!strcmp(s, "signed"))
		return TYPE;
	if (!strcmp(s, "unsigned"))
		return TYPE;
	if (!strcmp(s, "short"))
		return TYPE;
	if (!strcmp(s, "int"))
		return TYPE;
	if (!strcmp(s, "long"))
		return TYPE;
	if (!strcmp(s, "float"))
		return TYPE;
	if (!strcmp(s, "double"))
		return TYPE;
	if (!strcmp(s, "struct"))
		return TYPE;
	if (!strcmp(s, "union"))
		return TYPE;
	if (!strcmp(s, "enum"))
		return TYPE;
	return IDENTIFIER;
}

/* read next token into "this" */
void gettoken(void)
{
	char *p = this.string;

	/* read past any spaces */
	while ((*p = getchar()) == ' ')
		;

	if (isalnum(*p)) {
		/* it starts with A-Z,0-9 read in identifier */
		while (isalnum(*++p = getchar()))
			;
		ungetc(*p, stdin);
		*p = '\0';
		this.type = classify_string();
		return;
	}

	if (*p == '*') {
		strcpy(this.string, "pointer to");
		this.type = '*';
		return;
	}
	this.string[1] = '\0';
	this.type = *p;
	return;
}

void initialize(void), get_array(void), get_params(void),
     get_lparen(void), get_ptr_part(void), get_type(void);

void (*nextstate)(void) = initialize;

/* Cdecl written as a finite state machine */
int main(void)
{
	/* transition through the states, until the pointer is null */
	while (nextstate != NULL)
		(*nextstate)();

	return 0;
}

void initialize(void)
{
	gettoken();
	while (this.type != IDENTIFIER) {
		push(this);
		gettoken();
	}
	printf("%s is ", this.string);
	gettoken();
	nextstate = get_array;
}

void get_array(void)
{
	nextstate = get_params;
	while (this.type == '[') {
		printf("array ");
		gettoken(); /* a number or ']' */
		if (isdigit(this.string[0])) {
			printf("0..%d ", atoi(this.string)-1);
			gettoken(); /* read the ']' */
		}
		gettoken(); /* read next past the ']' */
		printf("of ");
		nextstate = get_lparen;
	}
}

void get_params(void)
{
	nextstate = get_lparen;
	if (this.type == '(') {
		while (this.type != ')') {
			gettoken();
		}
		gettoken();
		printf("function returning ");
	}
}

void get_lparen(void)
{
	nextstate = get_ptr_part;
	if (top >= 0) {
		if (stack[top].type == '(') {
			pop;
			/* read past ')' */
			gettoken();
			nextstate = get_array;
		}
	}
}

void get_ptr_part(void)
{
	nextstate = get_type;
	if (stack[top].type == '*') {
		printf("pointer to ");
		pop;
		nextstate = get_lparen;
	} else if (stack[top].type == QUALIFIER) {
		printf("%s ", pop.string);
		nextstate = get_lparen;
	}
}

void get_type(void)
{
	nextstate = NULL;
	/* process tokens that we stacked while reading to identifier */
	while (top >= 0) {
		printf("%s ", pop.string);
	}
	printf("\n");
}
