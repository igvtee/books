#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <usock.h>

int main(void)
{
	int fd, cli;
	char buf[1024];
	ssize_t len;

	fd = usock(USOCK_TCP | USOCK_SERVER | USOCK_IPV4ONLY | USOCK_NUMERIC,
		   "127.0.0.1", "4545");
	if (fd < 0) {
		perror("usock");
		return 1;
	}

	while ((cli = accept(fd, NULL, NULL)) >= 0) {
		while (1) {
			len = recv(cli, buf, sizeof(buf), 0);
			if (-1 == len) {
				perror("recv");
				break;
			}
			if (len == 0)
				break;
			len = send(cli, buf, len, 0);
			if (-1 == len) {
				perror("send");
				break;
			}
		}
		close(cli);
	}

	close(fd);

	return 0;
}
