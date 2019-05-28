#include	"unp.h"

#undef	MAXLINE
#define	MAXLINE 65507

void show_bufsize(int sockfd)
{
	int n;
	socklen_t optlen;

	if (getsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &n, &optlen) < 0)
		err_sys("SO_RCVBUF getsockopt error");
	fprintf(stdout, "SO_RCVBUF = %d\n", n);

	if (getsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, &n, &optlen) < 0)
		err_sys("SO_SNDBUF getsockopt error");
	fprintf(stdout, "SO_SNDBUF = %d\n", n);
}

void
dg_echo(int sockfd, SA *pcliaddr, socklen_t clilen)
{
	int			n;
	socklen_t	len;
	char		mesg[MAXLINE];

	show_bufsize(sockfd);
	for ( ; ; ) {
		len = clilen;
		n = Recvfrom(sockfd, mesg, MAXLINE, 0, pcliaddr, &len);

		Sendto(sockfd, mesg, n, 0, pcliaddr, len);

		show_bufsize(sockfd);
	}
}
