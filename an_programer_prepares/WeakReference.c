static void bar(void) __attribute__((weakref("foo")));

int main(void)
{
	if(bar)
		bar();
}
