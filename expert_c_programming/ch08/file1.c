#include <stdio.h>

/* old style definition, but has prototype */
olddef(d, i)
	float d;
	char i;
{
	printf("olddef: float = %f, char = %x\n", d, i);
}

/* new style definition, but no prototype */
newdef(float d, char i)
{
	printf("newdef: float = %f, char = %x\n", d, i);
}
