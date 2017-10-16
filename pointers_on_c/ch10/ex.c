#include <stdio.h>

typedef struct {
	int a;
	short b[2];
} Ex2;

typedef struct EX {
	int a;
	char b[3];
	Ex2 c;
	struct EX *d;
} Ex;

int main(void)
{
	Ex x = {10, "Hi", {5, {-1, 25}}, 0};
	Ex *px = &x;
	int *pi;
	Ex y;

	/* pa->a = (*pa).a */
	pi = &px->a;
	printf("px: %p, pi: %p\n", px, pi);
	printf("pi: %d\n", *pi);
	printf("px->b[1]: %c\n", px->b[1]);
	printf("px->c.a: %d\n", px->c.a);
	printf("*px->c.b: %hd\n", *px->c.b);

	x.d = &y;
	px->d->a = 2;
	printf("px->d->a: %d\n", px->d->a);

	return 0;
}
