#include <stdio.h>

class Fruit {
	public:
		virtual void peel(void) {
			printf("peeling a base class fruit\n");
		};
		void slice(void);
		float juice(void);
	private:
		int weight, calories_per_oz;
};

class Apple : public Fruit {
	public:
		void peel(void) {
			printf("peeling an apple\n");
		};
		void make_candy_apple(float weight);
		void bob_for(int tub_id, int number_of_attempts);
};

void Fruit::slice(void)
{
}

float Fruit::juice(void)
{
}

int main(void)
{
	Apple apple;
	Fruit orange;
	Fruit *p;

	p = new Apple;
	p->peel();
	p->Fruit::peel();

	p = &apple;
	p->peel();
	p= &orange;
	p->peel();

	return 0;
}
