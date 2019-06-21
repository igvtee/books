#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysctl.h>

int main(void)
{
	struct {
		int low, pressure, high;
	} buf;
	size_t len = sizeof(buf);
	/* /proc/sys/net/ipv4/tcp_mem  */
	int name[] = {CTL_NET, NET_IPV4, NET_TCP_MEM};

	if (sysctl(name, sizeof(name)/sizeof(int), &buf, &len, NULL, 0) < 0) {
		perror("sysctl");
		exit(EXIT_FAILURE);
	}
	printf("tcp_mem: low=%d, pressure=%d, high=%d/n", buf.low,
	       buf.pressure, buf.high);

	return 0;
}
