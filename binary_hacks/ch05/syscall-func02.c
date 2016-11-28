#include <stdio.h>
#define __i386__
#include <unistd.h>
#include <sys/syscall.h>

int main(void)
{
	int ret;
	asm volatile (
			"int $0x80\n\t"
			: "=a" (ret)
			: "0" (__NR_getpid)
		     );
	printf("ret = %d pid = %d\n", ret, getpid());
	return 0;
}
