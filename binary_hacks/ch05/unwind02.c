#define UNW_LOCAL_ONLY
#include <libunwind.h>
#include <stdio.h>

void skip_func(void)
{
	unw_cursor_t cursor;
	unw_context_t uc;

	unw_getcontext(&uc);
	unw_init_local(&cursor, &uc);
	unw_step(&cursor);
	unw_step(&cursor);
	unw_resume(&cursor);
	printf("will be skipped.\n");
}

void skipped_func(void)
{
	skip_func();
	printf("will be skipped.\n");
}

int main(void)
{
	printf("start.\n");
	skipped_func();
	printf("end.\n");
	return 0;
}
