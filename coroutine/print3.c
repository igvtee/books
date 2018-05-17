#include <stdio.h>

int function(void) {
	static int i, state = 0;

	switch (state) {
	case 0: /* start of function */
		for (i = 0; i < 10; i++) {
			state = __LINE__ + 2; /* so we will come back to "case 1" */
			return i;
	case __LINE__:; /* resume control straight after the return */
		}
	}
	return -1;
}

int main(void)
{
	int i = 10;

	while (i--)
		printf("%d\n", function());
}
