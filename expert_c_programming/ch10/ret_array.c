#include <stdlib.h>

int (*paf())[20] {
	int (*pear)[20];
	pear = calloc(20, sizeof(int));
	return pear;
}

int main(void)
{
	int (*result)[20];

	result = paf();
	(*result)[3] = 12;

	return 0;
}
