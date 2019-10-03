#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <uloop.h>

void fd_cb(struct uloop_fd *u, unsigned int events __attribute__((unused)))
{
	char buf[1024];
	ssize_t len;

	len = read(u->fd, buf, sizeof(buf));
	if (len == -1) {
		perror("read");
		return;
	} else if (len > 0) {
		buf[len] = '\0';
		fputs(buf, stdout);
	}
}

int main(void)
{
	struct uloop_fd fd;

	uloop_init();

	memset(&fd, 0, sizeof(fd));
	fd.cb = fd_cb;
	fd.fd = fileno(stdin);
	uloop_fd_add(&fd, ULOOP_READ);

	uloop_run();
	uloop_done();

	return 0;
}
