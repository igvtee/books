#include <setjmp.h>
#include <signal.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

static struct sigaction orig_act;
static sigjmp_buf env;

static void sigsegv_handler(int sig)
{
	siglongjmp(env, 1);
}

int validate(void *addr)
{
	int is_valid = FALSE;
	struct sigaction act;

	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	act.sa_handler = sigsegv_handler;
	sigaction(SIGSEGV, &act, &orig_act);

	if (sigsetjmp(env, TRUE) == 0) {
		/* touch */
		volatile char c;
		c = *((char *)addr);	/* read */
		*((char *)addr) = c;	/* write */
		is_valid = TRUE;
	} else {
		is_valid = FALSE;
	}

	sigaction(SIGSEGV, &orig_act, NULL);
	return is_valid;
}

int main(void)
{
	int a;

	printf("variable a: %s\n", validate(&a) ? "valid" : "invalid");
	printf("100       : %s\n", validate((void *)100) ? "valid" : "invalid");
	return 0;
}
