#include <cstdlib>

int * leaky_foo(void) {
	int * a = new int;
	int * b = new int; // (bug 1) memory leak
	return a;
}

static int *c;

int main(int argc, char **argv) {
	c = leaky_foo(); // (bug 2) memory leak
	char *d = (char *)std::malloc(sizeof(char) * 10U);
	delete[] d; // (bug 3) should use free
}
