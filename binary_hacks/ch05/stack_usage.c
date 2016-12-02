#include <stdio.h>
#include <stddef.h>

#define MAX_STACK_SIZE (16 * 1024 * 1024)
static ptrdiff_t max_usage = 0;

__attribute__((no_instrument_function))
void __cyg_profile_func_enter(void *func_address, void *call_site)
{
	extern void *__libc_stack_end;
	const ptrdiff_t usage = __libc_stack_end - __builtin_frame_address(0);
	if (usage < MAX_STACK_SIZE && usage > max_usage) {
		max_usage = usage;
	}
}

__attribute__((no_instrument_function, destructor))
static void print_usage(void)
{
	printf("stack usage: %td bytes\n", max_usage);
}
