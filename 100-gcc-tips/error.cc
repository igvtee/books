#include <iostream>

class Foo {
public:
	void print() const {
		std::cout << (int)(this) << "\n";
	}
};

int main()
{
	class Foo foo;

	foo.print();
	return 0;
}
