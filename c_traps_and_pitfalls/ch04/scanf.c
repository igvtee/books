#include <stdio.h>

int main(void)
{
	int i;
	char c;

	for (i = 0; i < 5; i++) {
		scanf("%d", &c);
		printf("%d ", i);
	}
	printf("\n");

	return 0;
}
