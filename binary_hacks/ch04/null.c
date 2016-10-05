#include <stdio.h>
#include <stdarg.h>

void foo(const char *name, ...)
{
	va_list va;
	char *p;

	printf("%s\n", name);
	va_start(va, name);
	while ((p = va_arg(va, char *)))
		printf("%s\n", p);
	va_end(va);
}

int main(void)
{
	foo("foo", "bar", 0);
	return 0;
}
