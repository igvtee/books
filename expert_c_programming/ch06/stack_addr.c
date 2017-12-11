#include <stdio.h>

int j[1000];
int k[1000] = {1};

int main(void)
{
	int i;

	printf("The stack top is near %p\n", &i);
	printf("The bss is near %p\n", &j);
	printf("The data is near %p\n", &k);

	return 0;
}
