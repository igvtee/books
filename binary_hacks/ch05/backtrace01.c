#include <execinfo.h>

void foo(void)
{
	void *trace[128];
	int n = backtrace(trace, sizeof(trace) / sizeof(trace[0]));
	backtrace_symbols_fd(trace, n, 1);
}

int main(void)
{
	foo();
	return 0;
}
