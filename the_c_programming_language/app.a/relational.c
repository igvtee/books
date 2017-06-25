#include <stdio.h>

struct test {
	int e1;
	short int e2;
	long int e3;
	int e4;
};

int main(void)
{
	int *pe1;
	short int *pe2;
	long int *pe3;
	int *pe4;
	struct test data;

	pe1 = &data.e1;
	pe2 = &data.e2;
	pe3 = &data.e3;
	pe4 = &data.e4;

	if (pe1 > pe2)
		printf("e1 > e2\n");
	else if (pe1 == pe2)
		printf("e1 == e2\n");
	else
		printf("e1 < e2\n");

	if (pe1 > pe4)
		printf("e1 > e4\n");
	else if (pe1 == pe4)
		printf("e1 == e4\n");
	else
		printf("e1 < e4\n");

	return 0;
}
