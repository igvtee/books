#include "syscalls.h"

/* fseek: seek with a file pointer */
int fseek(FILE *fp, long offset, int origin)
{
	unsigned nc;	/* # of chars to flush */
	long rc = 0;	/* return code */

	if (fp->flag & _READ) {
		if (origin == 1)	/* from current position? */
			offset -= fp->cnt;	/* remember chars in buffer */
		rc = lseek(fp->fd, offset, origin);
		fp->cnt = 0;		/* no characters buffered */
	} else if (fp->flag & _WRITE) {
		if ((nc = fp->ptr - fp->base) > 0)
			if (write(fp->fd, fp->base, nc) != nc)
				rc = -1;
		if (rc != -1)	/* no errors yes? */
			rc = lseek(fp->fd, offset, origin);
	}
	return (rc == -1) ? -1 : 0;
}

int main(void)
{
	FILE *fp;
	int c;
	FILE *fopen(char *name, char *mode);

	fp = fopen("./Makefile", "r");
	if (!fp)
		return -1;
	c = getc(fp);
	if (c == EOF)
		return -1;
	fseek(fp, 0L, 2);

	return 0;
}
