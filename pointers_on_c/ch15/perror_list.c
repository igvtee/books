#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int main(void)
{
	const char *err;

	stdout = freopen("/proc/self/fd/1", "w", stderr);
	if (!stdout) {
		perror("freopen ");
		return -1;
	}

	for (errno = 0; errno < 150; errno++) {
		printf("perror[%d] = ", errno);
		perror(NULL);
	}

	return 0;
}
