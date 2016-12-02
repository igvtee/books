#include <unistd.h> /* sysconf */
#include <stdint.h> /* uintptr_t */
#include <stdio.h>

#pragma weak __libc_stack_end
extern void *__libc_stack_end;

void * get_linux_stack_base(void)
{
	long pagesize = sysconf(_SC_PAGESIZE);
	return (void *)(((uintptr_t)__libc_stack_end + pagesize)
			& ~(pagesize - 1));
}

int main(void)
{
	void * base;

	base = get_linux_stack_base();
	printf("stack base: %p\n", base);

	return 0;
}
