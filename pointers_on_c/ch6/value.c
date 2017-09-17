#include <stdio.h>
#include <string.h>

union value {
	int ival;
	short hval[2];
	char cval[4];
	float fval;
};

int main(void)
{
	union value value;

	strncpy(value.cval, "glob", 4);
	printf("int: %d\n" \
	       "shot: %hd %hd\n" \
	       "char: %c%c%c%c\n" \
	       "float: %f\n",
	       value.ival,
	       value.hval[0], value.hval[1],
	       value.cval[0], value.cval[1],
	       value.cval[2], value.cval[3],
	       value.fval);

	return 0;
}
