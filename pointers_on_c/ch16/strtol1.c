#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void)
{
	long int ret;

	ret = strtol("12345", NULL, -5);
	if (ret == EINVAL) {
		perror("EINVAL ");
	} else if (ret == ERANGE) {
		perror("ERANGE ");
	} else 
		perror(NULL);

	return 0;
}
