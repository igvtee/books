#define _GNU_SOURCE
#include	"unp.h"

ssize_t	read_ucred(int, void *, size_t, struct ucred *);

void
str_echo(int sockfd)
{
	ssize_t			n;
	char			buf[MAXLINE];
	struct ucred cred;

again:
	while ( (n = read_ucred(sockfd, buf, MAXLINE, &cred)) > 0) {
		printf("PID of sender = %d\n", cred.pid);
		printf("real user ID = %d\n", cred.uid);
		printf("real group ID = %d\n", cred.gid);
		memset(&cred, 0, sizeof(cred));
		Writen(sockfd, buf, n);
	}

	if (n < 0 && errno == EINTR)
		goto again;
	else if (n < 0)
		err_sys("str_echo: read error");
}
