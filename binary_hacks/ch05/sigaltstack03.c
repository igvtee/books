#include <stdio.h>
#include <stdlib.h> /* malloc */
#include <signal.h>
#include <setjmp.h>
#include <sys/mman.h>

#define ALT_STACK_SIZE (64 * 1024)
#define ORIGINAL_RED_ZONE_SIZE (64 * 1024)
#define NEW_RED_ZONE_SIZE (4 * 1024)
#define FIXED_STACK_SIZE (2 * 1024 * 1024)
static sigjmp_buf return_point;

static void signal_handler(int sig, siginfo_t *sig_info, void *sig_data)
{
	if (sig == SIGSEGV)
		siglongjmp(return_point, 1);
}

static void meaningless_recursive_func(void)
{
	meaningless_recursive_func();
}

static void register_sigaltstack(void)
{
	stack_t newSS, oldSS;
	char * stack_base = (char *)((size_t)&newSS & ~(FIXED_STACK_SIZE-1));

	newSS.ss_sp = (void *)(stack_base + ORIGINAL_RED_ZONE_SIZE);
	newSS.ss_size = ALT_STACK_SIZE;
	newSS.ss_flags = 0;

	sigaltstack(&newSS, &oldSS);

	mmap(newSS.ss_sp, newSS.ss_size + NEW_RED_ZONE_SIZE, PROT_READ |
			PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);

	mprotect(stack_base + ORIGINAL_RED_ZONE_SIZE + ALT_STACK_SIZE,
			NEW_RED_ZONE_SIZE, PROT_NONE);
}

int main(int argc, char **argv)
{
	struct sigaction newAct, oldAct;

	register_sigaltstack();

	sigemptyset(&newAct.sa_mask);
	sigaddset(&newAct.sa_mask, SIGSEGV);
	newAct.sa_sigaction = signal_handler;
	newAct.sa_flags = SA_SIGINFO | SA_RESTART | SA_ONSTACK;

	sigaction(SIGSEGV, &newAct, &oldAct);

	if (sigsetjmp(return_point, 1) == 0) {
		meaningless_recursive_func();
	} else {
		fprintf(stderr, "stack overflow error\n");
	}

	return 0;
}
