#include <stdio.h>

int main(void)
{
	int a = 1;

	/* error!
	 * copy a and plus 1 to temp
	 * but can not assign temp to 10
	 */
	++a = 10;
	printf("%d\n", a);

	return 0;
}
