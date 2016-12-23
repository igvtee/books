void slow(void)
{
	int i;
	for (i = 0; i < 2000000; i++);
}

void f(void)
{
	int i;
	for (i = 0; i < 1000; i++)
		slow();
}

void g(void)
{
	int i;
	for (i = 0; i < 4000; i++)
		slow();
}

int main(void)
{
	f();
	g();
	return 0;
}
