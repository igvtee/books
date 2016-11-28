#include <string.h>

typedef enum {
	ENUM1,
	ENUM2
} TestEnum;

typedef union {
	int i;
	char b[4];
} TestUnion;

typedef struct TestDump_ {
	short s;
	int i;
	long l;
	unsigned long long ll;
	char c;
	char *str;
	void *ptr;
	void *const volatile *cvptr;
	struct TestDump_ *dump;
	int (*fp)(int, char *[]);
	int (*ifp)(int, char *[]);
	int array[10];
	TestEnum en;
	TestUnion un;
	struct {
	} no_name_struct;
} TestDump;

int main(int argc, char *argv[])
{
	TestDump d;
	d.s = 2;
	d.i = 3;
	d.l = 4;
	d.ll = 0xfffffffffffll;
	d.c = 'c';
	d.str = "hoge-";
	d.ptr = &d;
	d.cvptr = &d.ptr;
	d.fp = main;
	d.en = ENUM2;
	d.array[0] = 1;
	d.dump = &d;
	strcpy(d.un.b, "abc");

	return 0;
}
