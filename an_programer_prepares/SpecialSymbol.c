#include <stdio.h>

extern const void __executable_start;
extern const void etext, _etext, __etext;
extern const void edata, _edata;
extern const void end, _end;

int main(void)
{
	printf("Executable Start %p\n", &__executable_start);
	printf("Text End %p %p %p\n", &etext, &_etext, &__etext);
	printf("Data End %p %p\n", &edata, &_edata);
	printf("Executable End %p %p\n", &end, &_end);

	return 0;
}
