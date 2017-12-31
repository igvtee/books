#include <stdio.h>

class Fruit {
	public:
		void peel(void) 
		{
			printf("this ptr = %p\n", this);
			this->weight--;
			weight--;
		}
		void slice(int num);
		float juice(void);
	private:
		int weight, calories_per_oz;
};

void Fruit::slice(int num)
{
	weight = num;
}

float Fruit::juice(void)
{
	return 1.0/weight;
}

int main(void)
{
	Fruit apple;

	printf("address of apple=%p\n", &apple);
	apple.peel();

	return 0;
}
