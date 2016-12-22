#include <stdio.h>
#include <unistd.h>	/* for sysconf(3) */
#include <sys/mman.h>	/* for mprotect(2) */

void func(void)
{
	printf("1st.\n");

	asm(
			"slot:\n\t" \
			"nop\n\t" \
			"nop\n\t" \
			"after_slot:");

	printf("2st.\n");

	/* modify program memory to writeable */
	long pagesize = (int)sysconf(_SC_PAGESIZE);
	char *p = (char *)((long)func & ~(pagesize - 1L));
	mprotect(p, pagesize * 10L, PROT_READ | PROT_WRITE | PROT_EXEC);

	/* modify func nop part */
	asm(
			".byte 0xe8,0,0,0,0\n\t"
			"popl %%eax\n\t"
			"addl $0x14, %%eax\n\t"
			"subl $after_slot, %%eax\n\t"
			"shl $8, %%eax\n\t"
			"movb $0xeb, %%al\n\t"	/* EB is jmp (2 byte insn) */
			"movw %%ax, slot"
			: : : "eax"
	   );

	printf("3st.\n");
}

int main(void)
{
	func();
	func();
	return 0;
}
