#include <stdio.h>
#define __USE_GNU
#include <ucontext.h>

typedef struct layout {
	struct layout *ebp;
	void *ret;
} layout;

void skip_func(void)
{
	ucontext_t uc;
	layout *ebp = __builtin_frame_address(0);
	ebp = ebp->ebp;

	getcontext(&uc);
#ifdef __x86_64__
	uc.uc_mcontext.gregs[REG_RIP] = (greg_t)ebp->ret;
	uc.uc_mcontext.gregs[REG_RBP] = (greg_t)ebp->ebp;
#else
	uc.uc_mcontext.gregs[REG_EIP] = (greg_t)ebp->ret;
	uc.uc_mcontext.gregs[REG_EBP] = (greg_t)ebp->ebp;
#endif
	setcontext(&uc);

	printf("will be skipped.\n");
}

void skipped_func(void)
{
	skip_func();
	printf("will be skipped.\n");
}

int main(void)
{
	printf("start.\n");
	skipped_func();
	printf("end.\n");
	return 0;
}
