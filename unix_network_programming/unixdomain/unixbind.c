#include	"unp.h"

int
main(int argc, char **argv)
{
	int					sockfd;
	socklen_t			len;
	struct sockaddr_un	addr1, addr2;

	if (argc != 2)
		err_quit("usage: unixbind <pathname>");

	sockfd = Socket(AF_LOCAL, SOCK_STREAM, 0);

	unlink(argv[1]);		/* OK if this fails */

	bzero(&addr1, sizeof(addr1));
	addr1.sun_family = AF_LOCAL;
	strncpy(addr1.sun_path, argv[1], sizeof(addr1.sun_path)-1);
	Bind(sockfd, (SA *) &addr1, SUN_LEN(&addr1));

	len = sizeof(addr2);
	Getsockname(sockfd, (SA *) &addr2, &len);
	printf("bound name = %s, returned len = %d\n", addr2.sun_path, len);
	printf("sockaddr_un size = %zd, no sun_path size = %zd, family size = %zd\n",
			sizeof(addr1), sizeof(addr1) - sizeof(addr1.sun_path),
			sizeof(addr1.sun_family));
	printf("SUN_LEN = %zd, sun_path = %zd\n", SUN_LEN(&addr1),
			strlen(addr1.sun_path));

	exit(0);
}
