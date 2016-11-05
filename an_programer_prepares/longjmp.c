#include <setjmp.h>
#include <stdio.h>

jmp_buf b;
void f(void)
{
	longjmp(b, 1);
}

int main(void)
{
	if (setjmp(b))
		printf("World!\n");
	else {
		printf("Hello ");
		f();
	}
	return 0;
}
