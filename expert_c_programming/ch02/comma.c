#include <stdio.h>

int main(void)
{
	int i;

	/* the value of a comma operator is the value of the rightmost operand.
	 * but assignment has higher precedence.
	 */
	i = 1, 2;
	printf("i is: %d\n", i);

	return 0;
}
