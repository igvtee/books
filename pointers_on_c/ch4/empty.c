#include <stdio.h>

int main(void)
{
	int cnt;

	if (scanf("%d", &cnt) == 1 &&
	    cnt > 0) {
		while (cnt--)
			putchar('\n');
	}

	return 0;
}
