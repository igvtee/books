#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <errno.h>

int kbhit(void)
{
	int i;
	errno = 0;
	if (ioctl(0, FIONREAD, &i) < 0) {
		if (errno == EBADF)
			printf("errno: bad file number");
		if (errno == EINVAL)
			printf("errno: invalid argument");
	}
	/* return a count of chars available to read */
	return i;
}

int main(void)
{
	int i = 0;
	int c = ' ';

	system("stty raw -echo");
	printf("enter 'q' to quit\n");
	for (; c != 'q'; i++) {
		if (kbhit()) {
			c = getchar();
			printf("\n got %c, on iteration %d", c, i);
		}
	}
	system("stty cooked echo");

	return 0;
}
