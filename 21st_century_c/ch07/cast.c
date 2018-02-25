int main()
{
	double x = 7;
	double *xp = &x;
	int list[100];

	int val2 = xp;
	list[val2] = 12;	//clang warns about using a pointer as an int.

	list[(int)xp] = 12;	//clang gives no warning.
}
