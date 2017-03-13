#include <stdio.h>

union uval {
	int ival;
	float fval;
	char *sval;
};

struct symtab {
	char *name;
	int flags;
	int utype;
	union uval u;
};
enum { INT, FLOAT, STRING };

void printval(struct symtab *sym)
{
	int utype = sym->utype;
	union uval u;

	u = sym->u;
	if (utype == INT)
		printf("%d\n", u.ival);
	else if (utype == FLOAT)
		printf("%f\n", u.fval);
	else if (utype == STRING)
		printf("%s\n", u.sval);
	else
		printf("bad type %d in utype\n", utype);
}

int main(void)
{
	struct symtab tab = { "myname", 0123, INT, {0x45} };

	printval(&tab);

	return 0;
}
