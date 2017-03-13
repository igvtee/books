#include <stdio.h>

struct strobj {
	int len;
	char *str;
};

int main(void)
{
	char buff[] = "abcdef";
	struct strobj data[] = {
		{1, "abcd"},
		{12, "efg"},
		{123, "h"},
	}, *p = data;

	/* increments len */
	printf("++p->len: 1 => %d\n", ++p->len);

	/* increments p before accessing len */
	printf("(++p)->len: %d\n", (++p)->len);

	/* increments p afterward */
	printf("(p++)->len (p++->len): %d \n", (p++)->len);
	printf("p->len: %d\n", p->len);

	p = data;
	printf("p->str: %s %s\n", (*p).str, p->str);

	/* fetches whatever str points to */
	printf("*p->str: %c\n", *p->str);

	/* increments str after accessing whatever it points to */
	printf("*p->str++ (~= *s++): %c\n", *p->str++);	// a
	printf("p->str: %c\n", *p->str);		// b

	data[0].str = buff;
	/* increments whatever str points to */
	printf("(*p->str)++: %c\n", (*p->str)++);	// a => b
	printf("p->str: %s\n", p->str);			// bbcdef

	/* increments p after accessing whatever str points to */
	printf("*p++->str: %c\n", *p++->str);		// b
	printf("p->str: %s\n", p->str);			// efg

	return 0;
}
