#include <inttypes.h>
#include <stdio.h>

int main(void)
{
	void *foo;
	intptr_t k = (intptr_t) &foo;
	void *ptr = &k;

	printf("The value of k is %" PRIdPTR "\n", k);
	printf("The value of ptr is %p\n", ptr);

	return 0;
}
