#include <stdio.h>
#include "calc.h"

#define MAXVAL	100	/* maximum depth of vval stack */

static double val[MAXVAL];	/* value stack */
static double *sp = val;	/* next free stack position */

/* push: push f onto value stack */
void push(double f)
{
	if (sp != val + MAXVAL)
		*sp++ = f;	/* push val onto stack */
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value form stack */
double pop(void)
{
	if (sp != val)
		return *--sp;	/* pop top of stack into val */
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}
