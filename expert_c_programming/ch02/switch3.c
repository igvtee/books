#include <stdio.h>

int main(void)
{
	int i = 1;
	const int two = 2;

	switch (i) {
		case 1: printf("case 1\n");
		case two: printf("case 2\n");
		case 3: printf("case 3\n");
		default: ;
	}

	return 0;
}
