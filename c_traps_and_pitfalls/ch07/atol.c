long atol(char *s)
{
	long r = 0;
	int neg = 0;

	switch (*s) {
		case '-':
			neg = 1;
			/* fall through */
		case '+':
			s++;
			break;
	}

	while (*s >= '0' && *s <= '9') {
		int n = *s++ - '0';
		if (neg)
			n = -n;
		r = r * 10 + n;
	}

	return r;
}
