void foo();
void foo_local();
void bar();

int main(void)
{
	foo();
	/* scoping limit */
	//foo_local();
	bar();
	return 0;
}
