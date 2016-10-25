#include <stdio.h>

void func(void)
{
}

int main(void)
{
	printf("%p\n", &func);
	return 0;
}
