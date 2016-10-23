int foo(void)
{
	return 123;
}

int f(int x, int y)
{
	int a = 0, b = 0;
	return (x + y + a + b);
}

int main(void)
{
	int a;

	foo();
	a = f(1, 3);
	return 0;
}
