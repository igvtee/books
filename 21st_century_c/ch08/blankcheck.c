#include <stdio.h>

#define Blankcheck(a) { \
	int aval = (#a[0] == '\0') ? 2 : (a+0); \
	printf("I understand your input to be %i.\n", aval); \
}

int main()
{
	Blankcheck(0);	//will set aval to zero.
	Blankcheck();	//will set aval to two.
}
