#include <stdio.h>

size_t my_strlen(const char *s, size_t n)
{
	const char *e = s + n;
	size_t num = 0;

	while (s < e && *s) {
		num++;
		s++;
	}

	return num;
}

int main(void)
{
	char str[] = "Hello world.";

	printf("%s %zu\n", str, my_strlen(str, 100));
	printf("%s %zu\n", str, my_strlen(str, 5));

	return 0;
}
