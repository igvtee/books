#define _GNU_SOURCE
#include <dlfcn.h>	// dlsym
#include <string.h>	// memset
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>	// inget_aton
#include <stdlib.h>	// getenv

static int (*bind0)(int sockfd, const struct sockaddr *myaddr,
		socklen_t addrlen);
static struct in_addr sin_addr;

void __attribute__((constructor)) init_bind0(void)
{
	bind0 = dlsym(RTLD_NEXT, "bind");
	inet_aton(getenv("BIND_ADDR"), &sin_addr);
}

int bind(int sockfd, const struct sockaddr *my_addr, socklen_t addrlen)
{
	struct sockaddr_in saddr;

	if (my_addr->sa_family == AF_INET &&
			((struct sockaddr_in *)my_addr)->sin_addr.s_addr ==
			INADDR_ANY)
	{
		memset(&saddr, 0, sizeof(saddr));
		saddr.sin_family = AF_INET;
		saddr.sin_port = ((struct sockaddr_in *)my_addr)->sin_port;
		saddr.sin_addr = sin_addr;

		return (*bind0)(sockfd, (const struct sockaddr *)&saddr,
				sizeof(saddr));
	}
	return (*bind0)(sockfd, my_addr, addrlen);
}
