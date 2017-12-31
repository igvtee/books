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
		Fruit(int i, int j); // constructor
		~Fruit(void); // destructor
	private:
		int weight, calories_per_oz;
};

Fruit::Fruit(int i, int j)
{
	weight = i;
	calories_per_oz = j;
	printf("constructor\n");
}

Fruit::~Fruit(void)
{
	printf("destructor\n");
}

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
	Fruit melon(4, 5), banana(12, 8);

	return 0;
}
