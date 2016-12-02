#define UNW_LOCAL_ONLY
#include <libunwind.h>
#include <stdio.h>

void show_backtrace(void)
{
	unw_cursor_t cursor;
	unw_context_t uc;
	unw_word_t ip, sp;
	char buf[256];
	unw_word_t offset;

	unw_getcontext(&uc);
	unw_init_local(&cursor, &uc);
	while (unw_step(&cursor) > 0) {
		unw_get_reg(&cursor, UNW_REG_IP, &ip);
		unw_get_reg(&cursor, UNW_REG_SP, &sp);
		unw_get_proc_name(&cursor, buf, sizeof(buf), &offset);
		printf("%p <%s+0x%x>\n", (void *)ip, buf, (unsigned int)offset);
	}
}

void func(void)
{
	show_backtrace();
}

int main(void)
{
	func();
	return 0;
}
