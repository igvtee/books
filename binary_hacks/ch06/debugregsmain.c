#include <stdio.h>
#define __USE_GNU
#include <signal.h>
#include <sys/ucontext.h>

void set_debugregs(unsigned long *v);
int tmp, data0, data1;
void func(void) {}

static unsigned long regs[] = {
	(unsigned long)&data0,
	(unsigned long)&data1,
	(unsigned long)func,
	0, /* unused */
	0, /* reserved */
	0, /* reserved */
	0, /* can't read */
	0x00fd013f, /* Trap condition. DR0: write, DR1: read/write, DR2: execute, DR3: unused */
};

#define TRY(x) do { fputs("Trying " #x "\n", stderr); x; } while (0)

static void trap_handler(int n, siginfo_t *si, struct ucontext *uc)
{
	fprintf(stderr, "  Trapped at 0x%08lx\n",
			(long unsigned int)uc->uc_mcontext.gregs[REG_EIP]);
        if (uc->uc_mcontext.gregs[REG_EIP] == regs[2]) {
		regs[7] = 0;
		set_debugregs(regs);
	}
}

int main(void)
{
	struct sigaction sa = {
		.sa_sigaction = (void *)trap_handler,
		.sa_flags = SA_RESTART | SA_SIGINFO,
	};

	sigemptyset(&sa.sa_mask);
	sigaction(SIGTRAP, &sa, NULL);
	set_debugregs(regs);

	TRY(tmp = data0);
	TRY(tmp = data1);
	TRY(data0 = 1);
	TRY(data1 = 1);
	TRY(func());

	return 0;
}
