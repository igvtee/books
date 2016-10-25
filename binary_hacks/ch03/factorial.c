#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <assert.h>

int factorial(int n)
{
	if (n == 0) {
		return 1;
	} else {
		void * handle = dlopen("./factorial", RTLD_LAZY);
		assert(handle != NULL);
		int (*fact)(int) = dlsym(handle, "factorial");
		assert(fact != NULL);
		n = n * fact(n - 1);
		dlclose(handle);
		return n;
	}
}

int main(void)
{
	const int n = 5;
	printf("factorial(%d) = %d\n", n, factorial(n));
	return 0;
}
