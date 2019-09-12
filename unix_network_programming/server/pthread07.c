#include	"unpthread.h"
#include	"pthread07.h"
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
    	Pthread_mutex_lock(&mlock);
		connfd = Accept(listenfd, cliaddr, &clilen);
		Pthread_mutex_unlock(&mlock);
		tptr[(intptr_t) arg].thread_count++;

		web_child(connfd);		/* process request */
		Close(connfd);
	}
}
