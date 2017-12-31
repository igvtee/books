#include <stdio.h>

class Fruit {
	public:
		void peel(void); 
		void slice(int num);
		float juice(void);
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

void Fruit::slice(int num)
{
}

float Fruit::juice(void)
{
}

int main(void)
{
	Apple teachers;

	return 0;
}
