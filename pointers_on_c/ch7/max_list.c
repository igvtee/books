#include <stdio.h>
#include <stdarg.h>

int max_list(int num, ...)
{
	va_list var_arg;
	int tmp, max;

	if (num < 0)
		return -1;

	max = num;
	va_start(var_arg, num);
	while ((tmp = va_arg(var_arg, int)) >= 0)
		if (tmp > max)
			max = tmp;
	va_end(var_arg);

	return max;
}

int main(void)
{
	printf("%d\n", max_list(3, 4, 5, 1, -10, 3));
	printf("%d\n", max_list(-3));

	return 0;
}
