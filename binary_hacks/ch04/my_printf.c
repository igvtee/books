#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#include <syslog.h>

__attribute__((format(printf, 1, 2)))
void my_printf(const char *my_format, ...)
{
	va_list ap;
	assert(my_format != NULL);
	va_start(ap, my_format);
	vprintf(my_format, ap);
	vsyslog(LOG_ERR, my_format, ap);
	va_end(ap);
}

int main(void)
{
	const char * format = "%d\n";
	my_printf(format, 100);
	return 0;
}
