/* version 1 */
void printnum(long n, void (*p)())
{
	if (n < 0) {
		(*p)('-');
		n = -n;
	}

	if (n >= 10)
		printnum(n/10, p);

	(*p)((int)(n % 10) + '0');
}

/* version 2 */
void printnum(long n, void (*p)())
{
	if (n < 0) {
		(*p)('-');
		n = -n;
	}

	if (n >= 10)
		printnum(n/10, p);

	(*p)("0123456789"[n % 10]);
}

/* version 3 */
void printneg(long n, void (*p)())
{
	if (n <= -10)
		printnum(n/10, p);

	(*p)("0123456789"[-(n % 10)]);
}

void printnum(long n, void (*p)())
{
	if (n < 0) {
		(*p)('-');
		printnum(n, p);
	} else
		printnum(-n, p);
}

/* version 4 */
void printneg(long n, void (*p)())
{
	long g;
	int r;

	q = n / 10;
	r = n % 10;
	if (r > 0) {
		r -= 10;
		q++;
	}
	if (n <= -10)
		printnum(q, p);

	(*p)("0123456789"[-r]);
}


