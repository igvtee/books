void bufwrite(char *p, int n)
{
	/* (n-- > 0) maybe slower */
	while (--n >= 0) {
		if (bufptr == &buffer[N])
			flushbuffer();
		*bufptr++ = *p++;
	}
}

void bufwrite(char *p, int n)
{
	while (n > 0) {
		int k, rem;

		if (bufptr == &buffer[N])
			flushbuffer();
		rem = N - (bufptr - buffer);
		k = (n > rem)? rem : n;
		memcpy(bufptr, p, k);
		bufptr += k;
		p += k;
		n -= k;
	}
}
