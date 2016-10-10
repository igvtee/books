#include <stdio.h>

extern unsigned char _binary_ImageSection_c_start[];
extern unsigned char _binary_ImageSection_c_end;
extern unsigned char _binary_ImageSection_c_size;

int main(void)
{
	unsigned char *p = _binary_ImageSection_c_start;

	while (p != &_binary_ImageSection_c_end)
		putchar(*p++);

	printf("image size: %d\n", (size_t)&_binary_ImageSection_c_size);
	return 0;
}
