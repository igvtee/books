#include <stdio.h>
#include <ctype.h>

#define MYPRINT(x) printf("%s: %d\n", #x, x)

int main(void)
{
	int ch;
	int cntrl, space, digit, lower, upper, punct, nprint;

	cntrl = space = digit = lower = upper = punct = nprint = 0;
	while ((ch = getchar()) != EOF) {
		if (iscntrl(ch))
			cntrl++;
		else if (isspace(ch))
			space++;
		else if (isdigit(ch))
			digit++;
		else if (islower(ch))
			lower++;
		else if (isupper(ch))
			upper++;
		else if (ispunct(ch))
			punct++;
		else if (!isprint(ch))
			nprint++;
	}

	MYPRINT(cntrl);
	MYPRINT(space);
	MYPRINT(digit);
	MYPRINT(lower);
	MYPRINT(upper);
	MYPRINT(punct);
	MYPRINT(nprint);

	return 0;
}
