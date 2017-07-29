#include <stdio.h>

int main(void)
{
	enum Liquid {
		OUNCE = 1,
		CUP = 8,
		PINT = 16,
		QUART = 32,
		GALLON = 128
	};
	enum Liquid jar;

	jar = QUART;
	printf("%s\n", jar);
	jar = jar + PINT;
	printf("%s\n", jar);

	return 0;
}
