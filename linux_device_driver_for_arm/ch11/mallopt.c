#include <malloc.h>
#include <sys/mman.h>
#include <stdlib.h>

#define SOMESIZE (100*1024*1024)
#define PAGE_SIZE 4096

int main(int argc, char *argv[])
{
	unsigned char *buffer;
	int i;

	if (mlockall(MCL_CURRENT | MCL_FUTURE))
		mallopt(M_TRIM_THRESHOLD, -1);
	mallopt(M_MMAP_MAX, 0);

	buffer = malloc(SOMESIZE);
	if (!buffer)
		exit(-1);

	/*
	 * touch each page in this piece of memory to get it
	 * mapped into RAM
	 */
	for (i = 0; i < SOMESIZE; i += PAGE_SIZE)
		buffer[i] = 0;
	free(buffer);
	/* <do your RT-thing> */

	return 0;
}
