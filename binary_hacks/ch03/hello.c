#include <asm/unistd.h>
static int errno;

#define __syscall "syscall"
#define __syscall_clobber "r11","rcx","memory"
#define __syscall_return(type, res) \
	do { \
		if ((unsigned long)(res) >= (unsigned long)(-127)) { \
			errno = -(res); \
			res = -1; \
		} \
		return (type) (res); \
	} while (0)

#define _syscall1(type,name,type1,arg1) \
	type name(type1 arg1) \
{ \
	long __res; \
	__asm__ volatile (__syscall \
			: "=a" (__res) \
			: "" (__NR_##name),"D" ((long)(arg1)) : __syscall_clobber ); \
	__syscall_return(type,__res); \
}

#define _syscall3(type,name,type1,arg1,type2,arg2,type3,arg3) \
	type name(type1 arg1,type2 arg2,type3 arg3) \
{ \
	long __res; \
	__asm__ volatile (__syscall \
			: "=a" (__res) \
			: "" (__NR_##name),"D" ((long)(arg1)),"S" ((long)(arg2)), \
			"d" ((long)(arg3)) : __syscall_clobber); \
	__syscall_return(type,__res); \
}

_syscall1(int, exit, int, status);
_syscall3(int, write, int, fd, const void *, buf, unsigned long, count);

void hello(void)
{
	write(1, "Hello World!\n", 13);
	exit(0);
}
