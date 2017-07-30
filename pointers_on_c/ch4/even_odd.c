#include <stdio.h>

int main(void)
{
	int i;

	for (i = 1; i <= 4; i += 1) {
		switch (i % 2) {
		case 0:
			printf("even\n");
		case 1:
			printf("odd\n");
		}
	}

	return 0;
}
