#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static char onbss[128];

int main(void)
{
	char onstack[128];
	int uninitialized, dummy;
	char *onheap = (char *)malloc(128);

	dummy = onbss[128];
	dummy = onstack[150];

	if (uninitialized == 0)
		printf("hello world!\n");
	close(uninitialized);

	dummy = onheap[128];

	free(onheap);
	dummy = onheap[0];

	strcpy(onstack, "build one to throw away; you will anyway.");
	strcpy(onstack, onstack + 1);
	return 0;
}
