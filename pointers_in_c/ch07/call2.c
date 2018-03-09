int add( int a, int b)
{
	int z = a + b;
	return z;
}
int main(int argc, char* argv[])
{
	int (*funcptr)(int x, int y) = add;
	funcptr(10,20);
	return 0;
}
