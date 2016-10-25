#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

double func(void)
{
	return 3.14;
}

void allow_execution(const void *addr)
{
	long pagesize = sysconf(_SC_PAGESIZE);
	char * p = (char *)((long)addr & ~(pagesize - 1L));
	mprotect(p, pagesize * 10L, PROT_READ|PROT_WRITE|PROT_EXEC);
}

int main(void)
{
	void * p = malloc(1000);
	memcpy(p, func, 1000);
	allow_execution(p);
	printf("PI equals to %g\n", ((double (*)(void))p)());
	return 0;
}
