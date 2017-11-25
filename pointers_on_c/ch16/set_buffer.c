#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf jbuf;

void set_buffer(void)
{
	setjmp(jbuf);
}

int main(int ac, char **av)
{
	int a = atoi(av[1]);
	int b = atoi(av[2]);

	set_buffer();
	printf("%d plus %d equals %d\n", a, b, a+b);
	longjmp(jbuf, 1);
	printf("After longjmp\n");

	return EXIT_SUCCESS;
}
