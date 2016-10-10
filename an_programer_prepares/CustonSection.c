__attribute__((section("FOO")))
int global = 42;

__attribute__((section("BAR")))
void foo()
{
	puts("foo\n");
}

int main(void)
{
	foo();
	return 0;
}
