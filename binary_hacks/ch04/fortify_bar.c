#include <stdio.h>
#include <string.h>

static char buf[6];

int main(int argc, char * argv[])
{
	strcpy(buf, argv[1]);
	return 0;
}
