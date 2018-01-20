#include <stdio.h>
#include <stdarg.h>

void error(char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	fprintf(stderr, "error: ");
	vfprintf(stderr, format, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	exit(1);
}
