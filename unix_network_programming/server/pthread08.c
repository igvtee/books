#include	"unpthread.h"
#include	"pthread08.h"
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
	int		connfd;
	void	web_child(int);

	printf("thread %"PRIdPTR" starting\n", (intptr_t) arg);
	for ( ; ; ) {
    	Pthread_mutex_lock(&clifd_mutex);
		while (iget == iput)
			Pthread_cond_wait(&clifd_cond, &clifd_mutex);
		connfd = clifd[iget];	/* connected socket to service */
		if (++iget == MAXNCLI)
			iget = 0;
		Pthread_mutex_unlock(&clifd_mutex);
		tptr[(intptr_t) arg].thread_count++;

		web_child(connfd);		/* process request */
		Close(connfd);
	}
}
