#include <stdio.h>

#define Begin() static int state=0; switch(state) { case 0:
#define Yield(x) do { state=__LINE__; return x; case __LINE__:; } while (0)
#define End() }; return -1

int function(void) {
	static int i;
	Begin();
	for (i = 0; i < 10; i++)
		Yield(i);
	End();
}

int main(void)
{
	int i = 10;

	while (i--)
		printf("%d\n", function());
}
