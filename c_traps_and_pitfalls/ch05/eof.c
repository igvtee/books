#define EOF -1

int main(void)
{
	register int c;

	/* getchar maybe function call */
	while ((c = getchar()) != EOF)
		putchar(c);

	return 0;
}
