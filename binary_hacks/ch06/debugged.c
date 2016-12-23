#include <stdio.h>
#include <signal.h>

int being_debugged = 1;
void signal_handler(int signum)
{
	being_debugged = 0;
}

int main(void)
{
	signal(SIGTRAP, signal_handler);
	__asm__ __volatile__("int3");
	if (being_debugged)
		printf("being debugged\n");
	else
		printf("not being debugged\n");
	return 0;
}
