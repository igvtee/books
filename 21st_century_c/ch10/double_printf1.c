#include <stdio.h>

#define doubleprintf(human, ...) \
	do { \
		printf human; \
		fprintf(stderr, __VA_ARGS__); \
	} while(0)

int main()
{
	double x = -1;

	if (x < 0)
		doubleprintf(("x is negative (%g)\n", x),
				"NEGVAL: x=%g\n", x);
}
