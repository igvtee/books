#include <stdio.h>

class Fruit {
	public:
		void peel(void) {
			printf("in peel\n");
		}
		void slice(void);
		void juice(void);
	private:
		int weight, calories_per_oz;
};

void Fruit::slice(void)
{
	printf("in slice\n");
}

void Fruit::juice(void)
{
	printf("in juice\n");
}

int main(void)
{
	Fruit apple;

	printf("hello world\n");
	apple.peel();
	apple.slice();
	apple.juice();

	return 0;
}
