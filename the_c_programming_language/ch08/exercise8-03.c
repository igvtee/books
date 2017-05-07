#include "syscalls.h"
#include <stdlib.h>

/* _flushbuf: allocate and flush output buffer */
int _flushbuf(int x, FILE *fp)
{
	unsigned nc;	/* # of chars to flush */
	int bufsize;	/* size of buffer alloc */

	if (fp < _iob || fp >= _iob + OPEN_MAX)
		return EOF;
	if ((fp->flag & (_WRITE | _ERR)) != _WRITE)
		return EOF;
	bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
	if (fp->base == NULL) {	/* no buffer yet */
		if ((fp->base = (char *) malloc(bufsize)) == NULL) {
			fp->flag |= _ERR;
			return EOF;	/* can't get buffer */
		}
	} else {	/* buffer already exists */
		nc = fp->ptr - fp->base;
		if (write(fp->fd, fp->base, nc) != nc) {
			fp->flag |= _ERR;
			return EOF;	/* error: return EOF */
		}
	}
	fp->ptr = fp->base;	/* beginning of buffer */
	*fp->ptr++ = (char) x;	/* save current char */
	fp->cnt = bufsize - 1;
	return x;
}

/* fflush: flush buffer associated with file fp */
int fflush(FILE *fp)
{
	int rc = 0;

	if (fp < _iob || fp >= _iob + OPEN_MAX)
		return EOF;	/* error: invalid pointer */
	if (fp->flag & _WRITE)
		rc = _flushbuf(0, fp);
	fp->ptr = fp->base;
	fp->cnt = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
	return rc;
}

/* fclose: close file */
int fclose(FILE *fp)
{
	int rc;	/* return code */

	if ((rc = fflush(fp)) != EOF) {	/* anything to flush? */
		free(fp->base);		/* free allocated buffer */
		fp->ptr = NULL;
		fp->cnt = 0;
		fp->base = NULL;
		fp->flag &= ~(_READ | _WRITE);
	}
	return rc;
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
	fclose(fp);

	return 0;
}
