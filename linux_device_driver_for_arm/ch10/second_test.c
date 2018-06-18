#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	int fd;
	int counter = 0;
	int old_counter = 0;

	fd = open("/dev/second", O_RDONLY);
	if (fd == -1) {
		printf("device open failure\n");
		return 1;
	}

	while (1) {
		read(fd, &counter, sizeof(counter));
		if (counter != old_counter) {
			printf("seconds after open /dev/second : %d\n",
			       counter);
			old_counter = counter;
		}
	}
}
