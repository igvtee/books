#include <stdio.h>
#include <assert.h>
#include <ctype.h>

int my_atoi(const char *s)
{
	int ret = 0;

	assert(s != NULL);
	while (*s != '\0' && isdigit(*s)) {
		const int dig = *s - '0';
		ret *= 10;
		ret += dig;
		++s;
	}
	return ret;
}

int main(int argc, char *argv[])
{
	int num;

	num = my_atoi(argv[1]);
	printf("%d\n", num);

	return 0;
}
