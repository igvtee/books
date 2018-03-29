#define COMPILER_BARRIER() asm volatile("" ::: "memory")

int Value;
int IsPublished = 0;

void sendValue(int x)
{
	Value = x;
	COMPILER_BARRIER();          // prevent reordering of stores
	IsPublished = 1;
}

int tryRecvValue()
{
	if (IsPublished)
	{
		COMPILER_BARRIER();      // prevent reordering of loads
		return Value;
	}
	return -1;  // or some other value to mean not yet received
}
