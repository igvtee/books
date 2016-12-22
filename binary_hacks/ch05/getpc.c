#include <stdio.h>

void * getpc(void)
{
	void *p;
	asm(".byte 0xe8,0,0,0,0\n\t" /* call the following popl insn */
			"popl %0\n\t"
			: "=m" (p));
	return p;
}

void * getpc1(void)
{
	void *p;
	asm("call 1f; 1: popl %0"
			: "=m" (p));
	return p;
}

int main(void)
{
	void *pc, *pc1;
	pc = getpc();
	pc1 = getpc1();
	printf("%p %p\n", pc, pc1);
	return 0;
}
