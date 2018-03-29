typedef struct {
	int bar;
	int bar2;
} Foo;

void sendValue(int);

void doSomeStuff(Foo* foo)
{
    foo->bar = 5;
    sendValue(123);       // prevents reordering of neighboring assignments
    foo->bar2 = foo->bar;
}
