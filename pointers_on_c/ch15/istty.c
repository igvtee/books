#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	if (isatty(fileno(stdin)))
		puts("stdin is connected to a terminal");
	else
		puts("stdin is NOT connected to a terminal");
	return 0;
}
