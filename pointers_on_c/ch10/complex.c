#include <stdio.h>
#include "complex.h"

void func(struct COMPLEX *cp)
{
	(*cp).f;
	cp->f;
}

int main(void)
{
	struct COMPLEX comp;

	((comp.sa)[4]).c;
	comp.sa[4].c;

	return 0;
}
