static int a;
extern int b;
extern void ext();

static void bar(void)
{
	/* Type 2, Innter-module data access */
	a = 1;
	/* Type 4, Inter-module data access */
	b = 2;
}

void foo(void)
{
	/* Type 1, Inner-module call */
	bar();
	/* Type 3, Inter-module call */
	ext();
}
