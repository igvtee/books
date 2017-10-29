#include <stdio.h>

#define PRINTVALUE(x, y) printf("%-10s: "x"\n", #y, y)
#define PRINTERR(x) printf("%-10s: ERROR\n", #x)

typedef struct {
	int x;
	int y;
} Point;

int main(void)
{
	Point p = {1, 2};
	Point *a = &p;
	Point **b = &a;

	PRINTVALUE("%p", a);
	PRINTERR(*a);
	PRINTVALUE("%d", a->x);
	PRINTVALUE("%p", b);
	PRINTERR(b->a);
	PRINTERR(b->x);
	PRINTVALUE("%p", *b);
	PRINTERR(*b->a);
	PRINTERR(*b->x);
	PRINTERR(b->a->x);
	PRINTERR((*b)->a);
	PRINTVALUE("%d", (*b)->x);
	PRINTERR(**b);

	return 0;
}
