#include <stdio.h>

void stack_dump(void)
{
	void * frame, * addr;
	register void *stack_pointer asm ("%esp");
	register void *frame_pointer asm ("%ebp");

	printf("stack: %p, frame: %p\n", stack_pointer, frame_pointer);

	if (!(frame = __builtin_frame_address(0)))
		return;
	if (!(addr = __builtin_return_address(0)))
		return;
	printf("#0 %p %p\n", frame, addr);

	if (!(frame = __builtin_frame_address(1)))
		return;
	if (!(addr = __builtin_return_address(1)))
		return;
	printf("#1 %p %p\n", frame, addr);

	if (!(frame = __builtin_frame_address(2)))
		return;
	if (!(addr = __builtin_return_address(2)))
		return;
	printf("#2 %p %p\n", frame, addr);

	if (!(frame = __builtin_frame_address(3)))
		return;
	if (!(addr = __builtin_return_address(3)))
		return;
	printf("#3 %p %p\n", frame, addr);

	if (!(frame = __builtin_frame_address(4)))
		return;
	if (!(addr = __builtin_return_address(4)))
		return;
	printf("#4 %p %p\n", frame, addr);

	if (!(frame = __builtin_frame_address(5)))
		return;
	if (!(addr = __builtin_return_address(5)))
		return;
	printf("#5 %p %p\n", frame, addr);

	if (!(frame = __builtin_frame_address(6)))
		return;
	if (!(addr = __builtin_return_address(6)))
		return;
	printf("#6 %p %p\n", frame, addr);

	if (!(frame = __builtin_frame_address(7)))
		return;
	if (!(addr = __builtin_return_address(7)))
		return;
	printf("#7 %p %p\n", frame, addr);

	if (!(frame = __builtin_frame_address(8)))
		return;
	if (!(addr = __builtin_return_address(8)))
		return;
	printf("#8 %p %p\n", frame, addr);

	if (!(frame = __builtin_frame_address(9)))
		return;
	if (!(addr = __builtin_return_address(9)))
		return;
	printf("#9 %p %p\n", frame, addr);

}

void func2(void)
{
	printf("func2 %p\n", &func2);
	stack_dump();
}

void func1(void)
{
	printf("func1 %p\n", &func1);
	func2();
}

void func0(void)
{
	printf("func0 %p\n", &func0);
	func1();
}

int main(void)
{
	printf("main %p\n", &main);
	func0();
	return 0;
}
