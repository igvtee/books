int main(void)
{
	int ret;
	const char msg[] = "hello world.\n";
	__asm__ volatile (
			"call *%%esi"
			: "=a" (ret)
			: "a" (4),
			"S" (0xf7fd9a50),
			"b" ((long) 1),
			"c" ((long) msg),
			"d" ((long) sizeof(msg))
			);
	return 0;
}
