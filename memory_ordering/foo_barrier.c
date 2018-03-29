int A, B;

void foo()
{
	A = B + 1;
	asm volatile("" ::: "memory");
	B = 0;
}
