#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <uloop.h>

pid_t process_sleep(int secs)
{
	char sleep_secs[10];
	pid_t pid = 1;

	if ((pid = fork()) < 0) {
		perror("fork");
		return pid;
	}
	if (pid > 0)	// parent
		return pid;
	snprintf(sleep_secs, sizeof(sleep_secs), "%d", secs);
	if (execl("/usr/bin/sleep", "sleep", sleep_secs, NULL) < 0)
		perror("execl");
	return pid;
}

void p1_cb(struct uloop_process *c, int ret)
{
	printf("pid: %d, ret: %d\n", c->pid, ret);
	uloop_end();
}

int main(void)
{
	struct uloop_process p1;

	uloop_init();

	memset(&p1, 0, sizeof(p1));
	p1.cb = p1_cb;
	p1.pid = process_sleep(2);
	if (p1.pid < 0)
		return -1;
	uloop_process_add(&p1);

	uloop_run();
	uloop_done();
}
