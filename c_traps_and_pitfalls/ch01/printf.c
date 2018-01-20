#include <stdio.h>

int main(void)
{
	int c = 'yes';

	printf("%x\n", c);

	/* should be "\n" */
	printf('\n');

	return 0;
}
