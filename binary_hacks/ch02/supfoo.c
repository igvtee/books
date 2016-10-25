#include <stdio.h>
extern char _binary_supfoo_jpg_start[];
extern char _binary_supfoo_jpg_end[];
extern char _binary_supfoo_jpg_size[];

int main(void)
{
	printf("start: %p end: %p size: %p\n",
			_binary_supfoo_jpg_start,
			_binary_supfoo_jpg_end,
			_binary_supfoo_jpg_size);
	return 0;
}
