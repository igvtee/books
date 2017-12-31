#include <stdio.h>

class Fruit {
	public:
		void peel(void); 
		void slice(void);
		float juice(void);
		int operator+(Fruit &f);
	private:
		int weight, calories_per_oz;
};

class Apple : public Fruit {
	public:
		void make_candy_apple(float weight);
		void bob_for(int tub_id, int number_of_attempts);
};

void Fruit::peel(void) 
{
}

void Fruit::slice(void)
{
}

float Fruit::juice(void)
{
}

int Fruit::operator+(Fruit &f)
{
	printf("calling fruit addition\n");
	return weight + f.weight;
}

int main(void)
{
	Apple apple;
	Fruit orange;
	int ounces = apple + orange;

	return 0;
}
