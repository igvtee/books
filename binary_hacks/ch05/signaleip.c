#include <stdio.h>
#define __USE_GNU
#include <signal.h>

static unsigned long target;

void handler(int signum, siginfo_t *siginfo, void *uc0)
{
	struct ucontext *uc;

	uc = (struct ucontext *)uc0;
	uc->uc_mcontext.gregs[REG_EIP] = target;
}

int main(int argc, char **argv)
{
	struct sigaction act;

	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGTRAP, &act, NULL);

	asm("movl $skipped,%0" : : "m" (target));
	asm("int3"); /* cause SIGTRAP */

	printf("To be skipped.\n");
	asm("skipped:");
	printf("Done.\n");
}
