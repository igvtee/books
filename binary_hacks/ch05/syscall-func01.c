#include <stdio.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	int ret;
	ret = syscall(__NR_getpid);
	printf("ret = %d pid = %d\n", ret, getpid());
	return 0;
}
