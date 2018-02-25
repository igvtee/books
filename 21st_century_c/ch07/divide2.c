#include <stdio.h>

int main()
{
	double denom = 7;
	char *head = "There is a cycle to things divided by seven.";
	printf("%s\n", head);
	for (int i = 1; i <= 6; i++) {
		double ratio = i/denom;
		printf("%g\n", ratio);
	}
}
