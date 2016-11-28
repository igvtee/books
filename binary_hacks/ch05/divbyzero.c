int foo(void)
{
	return 1 / 0;
}

int main(void)
{
	foo();
	return 0;
}
