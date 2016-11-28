#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

int main(void)
{
	int ret;
	asm volatile (
			"syscall\n\t"
			: "=a" (ret)
			: "0" (__NR_getpid)
		     );
	printf("ret = %d pid = %d\n", ret, getpid());
	return 0;
}
