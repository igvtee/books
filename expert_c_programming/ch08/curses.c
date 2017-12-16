#include <stdio.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <curses.h>

int kbhit(void)
{
	int i;
	errno = 0;
	if (ioctl(0, FIONREAD, &i) < 0) {
		if (errno == EBADF)
			printf("errno: bad file number");
		if (errno == EINVAL)
			printf("errno: invalid argument");
	}
	return i;
}

int main(void)
{
	int i = 0;
	int c = ' ';

	/* initialize curses functions */
	initscr();
	cbreak();
	/* do not echo pressed character */
	noecho();

	mvprintw(0, 0, "Press 'q' to quit\n");
	refresh();

	while (c != 'q') {
		if (kbhit()) {
		/* won't block, as we know a character is waiting */
			c = getchar();
			mvprintw(1, 0, "got char %c, on iteration %d", c, ++i);
			refresh();
		}
	}

	nocbreak();
	echo();
	/* finish curses */
	endwin();

	return 0;
}
