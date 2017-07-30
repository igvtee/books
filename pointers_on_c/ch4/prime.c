#include <stdio.h>

#define MAX_NUMBER 100

int main(void)
{
	int num, tmp;

	for (num = 2; num <= MAX_NUMBER; num++) {
		for (tmp = 2; tmp <= num; tmp++) {
			if (num == tmp) {
				printf("%d ", num);
				break;
			}
			if (num % tmp == 0)
				break;
		}
	}
	putchar('\n');

	return 0;
}
