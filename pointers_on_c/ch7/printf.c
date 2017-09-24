#include <stdio.h>
#include <stdarg.h>

void print_integer(int num)
{
	printf("%d", num);
}

void print_float(float fnum)
{
	printf("%f", fnum);
}

int simple_printf(const char *format, ...)
{
	va_list var_arg;
	char cvalue;
	char *svalue;

	va_start(var_arg, format);
	while (*format) {
		switch (*format) {
		case '%':
			format++;
			switch (*format) {
			case 'd':
				print_integer(va_arg(var_arg, int));
				break;
			case 'f':
				print_float(va_arg(var_arg, double));
				break;
			case 's':
				svalue = va_arg(var_arg, char *);
				while (*svalue)
					putchar(*svalue++);
				break;
			case 'c':
				cvalue = va_arg(var_arg, int);
				putchar(cvalue);
				break;
			default:
				goto error;
				break;
			}
			break;
		default:
			putchar(*format);
			break;
		}
		format++;
	}
error:
	va_end(var_arg);
}

int main(void)
{
	simple_printf("== %d %f %s %c ===\n", 1234, 33.44, "string", 'c');

	return 0;
}
