#include	"unpthread.h"
#include	"pthread09.h"
#include <inttypes.h>

void
thread_make(intptr_t i)
{
	void	*thread_main(void *);

	Pthread_create(&tptr[i].thread_tid, NULL, &thread_main, (void *) i);
	return;		/* main thread returns */
}

void *
thread_main(void *arg)
{
	int				connfd;
	void			web_child(int);
	socklen_t		clilen;
	struct sockaddr	*cliaddr;

	cliaddr = Malloc(addrlen);

	printf("thread %"PRIdPTR" starting\n", (intptr_t) arg);
	for ( ; ; ) {
		clilen = addrlen;
		connfd = Accept(listenfd, cliaddr, &clilen);
		tptr[(intptr_t) arg].thread_count++;

		web_child(connfd);		/* process the request */
		Close(connfd);
	}
}
