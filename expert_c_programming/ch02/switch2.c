#include <stdio.h>

int main(void)
{
	int i = 8;

	switch (i) {
		case 5 + 3: do_again:
		case 2: printf("I loop unremittingly\n"); goto do_again;
		/* error should be l not 1(one) */
		defau1t: i++;
		case 3: ;
	}

	return 0;
}
