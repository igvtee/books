#include <stdio.h>

class Fruit {
	public:
		void peel(void) {
			printf("in peel\n");
		}
		void slice(int slice);
		float juice(void);
	private:
		int weight, calories_per_oz;
};

void Fruit::slice(int slice)
{
	printf("in slice %d\n", slice);
}

float Fruit::juice(void)
{
	printf("in juice %d\n", weight);
	return 1.5;
}

int main(void)
{
	Fruit apple;
	int weight;

	apple.peel();
	apple.slice(5);
	apple.juice();
	//weight = apple.weight;

	return 0;
}
