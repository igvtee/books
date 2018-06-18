#include <linux/netlink.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <poll.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>

static void die(char *s)
{
	write(2, s, strlen(s));
	exit(1);
}

int main(int argc, char *argv[])
{
	struct sockaddr_nl nls;
	struct pollfd pfd;
	char buf[512];

	// Open hotplug event netlink socket
	memset(&nls, 0, sizeof(nls));
	nls.nl_family = AF_NETLINK;
	nls.nl_pid = getpid();
	nls.nl_groups = -1;

	pfd.events = POLLIN;
	pfd.fd = socket(PF_NETLINK, SOCK_DGRAM, NETLINK_KOBJECT_UEVENT);
	if (pfd.fd == -1)
		die("Not root\n");

	// Listen to netlink socket
	if (bind(pfd.fd, (void *)&nls, sizeof(nls)))
		die("Bind failed\n");

	while (-1 != poll(&pfd, 1, -1)) {
		int i, len = recv(pfd.fd, buf, sizeof(buf), MSG_DONTWAIT);
		if (-1 == len)
			die("recv\n");

		// print the data to stdout.
		i = 0;
		while (i < len) {
			printf("%s\n", buf + i);
			i += strlen(buf + i) + 1;
		}
	}
	die("poll\n");
}
