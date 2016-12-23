#include <sys/user.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void set_debugregs(unsigned long *v)
{
	if (!fork()) {
		int i, *p = ((struct user *)0)->u_debugreg;
		pid_t ppid = getppid();
		ptrace(PTRACE_ATTACH, ppid, NULL, NULL);
		waitpid(ppid, NULL, 0);
		for (i = 0; i < 8; i++, p++, v++) {
			if (i == 4 || i == 5)
				continue;
			if (ptrace(PTRACE_POKEUSER, ppid, p, *v) < 0)
				fprintf(stderr, "ptrace failed: dr%d = %08lx\n", i, *v);
		}
		ptrace(PTRACE_DETACH, ppid, NULL, NULL);
		exit(0);
	}
	wait(NULL);
}
