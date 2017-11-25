#include <stdio.h>
#include <stdarg.h>

void myprintf(char const *format, ...)
{
	va_list ap;

	va_start(ap, format);
	vprintf(format, ap);
	/* no need va_end */
}

int main(int argc, char **argv)
{

	myprintf("%s %s %s\n", "hello", "the", "word");

	return 0;
}
