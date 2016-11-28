#include <stdio.h>

typedef struct layout {
	struct layout *ebp;
	void *ret;
} layout;

void print_backtrace(void)
{
	layout *ebp = __builtin_frame_address(0);
	while (ebp) {
		printf("%p %p\n", ebp, ebp->ret);
		ebp = ebp->ebp;
	}
}

void foo(void)
{
	print_backtrace();
}

int main(void)
{
	foo();
	return 0;
}
