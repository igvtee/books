#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <usock.h>
#include <string.h>

int main(void)
{
	int fd;
	char buf[1024];
	ssize_t len;

	fd = usock_inet_timeout(USOCK_TCP | USOCK_IPV4ONLY | USOCK_NUMERIC,
		   "127.0.0.1", "4545", NULL, 3000);
	if (fd < 0) {
		perror("usock");
		return 1;
	}

	while (fgets(buf, sizeof(buf), stdin) != NULL) {
		len = send(fd, buf, strlen(buf), 0);
		if (-1 == len) {
			perror("send");
			return 1;
		}
		len = recv(fd, buf, sizeof(buf), 0);
		if (-1 == len) {
			perror("recv");
			return 1;
		}
		buf[len] = '\0';
		fputs(buf, stdout);
	}

	close(fd);

	return 0;
}
