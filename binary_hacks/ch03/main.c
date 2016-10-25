#include <stdio.h>

__attribute__((constructor))
void foo(void)
{
	printf("hello, before main\n");
}

int main(void)
{
	printf("hello, world\n");
	return 0;
}

__attribute((destructor))
void bar(void)
{
	printf("hello, after main\n");
}
