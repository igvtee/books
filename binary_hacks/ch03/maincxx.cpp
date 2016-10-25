#include <stdio.h>

void foo(void)
{
	printf("hello, before main\n");
}

void bar(void)
{
	printf("hello, after main\n");
}

namespace {
	struct foo_caller {
		foo_caller() {
			foo();
		}
		~foo_caller() {
			bar();
		}
	} caller;
}

int main(void)
{
	printf("hello, world\n");
	return 0;
}
