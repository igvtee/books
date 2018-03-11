#include <stdio.h>

#define fileprintf(...) fprintf(stderr, __VA_ARGS__)
#define doubleprintf(human, machine) \
	do { \
		printf human; \
		fileprintf machine; \
	} while(0)

int main()
{
	double x = -1;

	if (x < 0)
		doubleprintf(("x is negative (%g)\n", x),
				("NEGVAL: x=%g\n", x));
}
