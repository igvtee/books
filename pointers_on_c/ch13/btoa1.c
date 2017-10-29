void binary_to_ascii(unsigned int value)
{
	putchar("0123456789ABCDEF" [value % 16]);
}
