#include	"unpthread.h"

static void	*doit(void *);		/* each thread executes this function */

int
main(int argc, char **argv)
{
	int				listenfd = -1, connfd;
	pthread_t		tid;
	socklen_t		addrlen, len;
	struct sockaddr	*cliaddr;

	if (argc == 2)
		listenfd = Tcp_listen(NULL, argv[1], &addrlen);
	else if (argc == 3)
		listenfd = Tcp_listen(argv[1], argv[2], &addrlen);
	else
		err_quit("usage: tcpserv01 [ <host> ] <service or port>");

	cliaddr = Malloc(addrlen);

	for ( ; ; ) {
		len = addrlen;
		connfd = Accept(listenfd, cliaddr, &len);
		Pthread_create(&tid, NULL, &doit, (void *) (intptr_t) connfd);
	}
}

static void *
doit(void *parg)
{
	int arg = (intptr_t)parg;
	Pthread_detach(pthread_self());
	str_echo(arg);	/* same function as before */
	Close(arg);		/* done with connected socket */
	return(NULL);
}
