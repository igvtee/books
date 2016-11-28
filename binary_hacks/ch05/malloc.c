#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define SLEEP 7

void do_malloc(size_t size)
{
	void *mem;
	mem = malloc(size * 1024);
	if (mem == NULL) {
		printf("memory exhausted\n");
		exit(1);
	}
	printf("%zu KB allocated\n", size);
	sleep(SLEEP);
}

#define STACKSIZE (1024 * 1024)
void do_stack(void)
{
	int stack[STACKSIZE];
	stack[STACKSIZE - 1] = 0;
	printf("stack 1MB allocated\n");
	sleep(SLEEP);
}

int main(void)
{
	printf("process %u started\n", getpid());
	sleep(SLEEP);
	do_malloc(8);
	do_malloc(100);
	do_malloc(100);
	do_malloc(1024);
	do_stack();
	exit(0);
}
