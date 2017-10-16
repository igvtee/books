#include <stdio.h>
#include <inttypes.h>

#define PRINT(x, y) printf("%-16s:"x"\n", #y, y)
#define PRINTINT(x) printf("%-16s:%d\n", #x, x)
#define PRINTADR(x) printf("%-16s:%" PRIu64 "\n", #x, \
		(uintptr_t)(x)-(uintptr_t)nodes+200)
#define PRINTERR(x) printf("%-16s:ERROR\n", #x)

struct NODE {
	int a;
	struct NODE *b;
	struct NODE *c;
};

struct NODE nodes[5] = {
	{5, nodes + 3, NULL},
	{15, nodes + 4, nodes + 3},
	/* *np */
	{22, NULL, nodes + 4},
	/* 3 */
	{12, nodes + 1, nodes},
	{18, nodes + 2, nodes + 1},
};

int main(void)
{
	struct NODE *np = nodes + 2;
	struct NODE **npp = &nodes[1].b;
	int aa[3] = {1, 2, 3};

	PRINTADR(nodes);
	PRINTERR(nodes.a);
	PRINTINT(nodes[3].a);
	PRINTADR(nodes[3].c);
	PRINTINT(nodes[3].c->a);
	PRINTERR(*nodes);
	PRINTERR(*nodes.a);
	PRINTINT((*nodes).a);
	PRINTINT(nodes->a);
	PRINTADR(nodes[3].b->b);
	PRINTERR(*nodes[3].b->b);
	PRINTADR(&nodes);
	PRINTADR(&nodes[3].a);
	PRINTADR(&nodes[3].c);
	PRINTADR(&nodes[3].c->a);
	PRINTADR(&nodes->a);
	PRINTADR(np);
	PRINTINT(np->a);
	PRINTINT(np->c->c->a);
	PRINTADR(npp);
	PRINTERR(npp->a);
	PRINTADR(*npp);
	PRINTERR(**npp);
	PRINTERR(*npp->a);
	PRINTINT((*npp)->a);
	PRINTADR(&np->a);
	PRINTADR(&np->c->c->a);

	return 0;
}
