#include <stdio.h>

int main(void)
{
	int n = 37;

	printf("There %s %d item%s in the list.\n",
			n!=1 ? "are" : "is", n, n!=1 ? "s" : "");

	return 0;
}
