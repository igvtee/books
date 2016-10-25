#define EXPORT __attribute__((visibility("default")))

EXPORT void func1() {}
void func2() {}

struct EXPORT Foo {
	void func();
};

void Foo::func() {}

struct Bar {
	void func();
};

void Bar::func() {}
