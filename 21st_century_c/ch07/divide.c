#include <stdio.h>

int main()
{
	char *head;
	int i;
	double ratio, denom;

	denom = 7;
	head = "There is a cycle to things divided by seven.";
	printf("%s\n", head);
	for (i = 1; i <= 6; i++) {
		ratio = i/denom;
		printf("%g\n", ratio);
	}
}
