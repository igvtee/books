void generate_initializer(char *string)
{
	static char separator = ' ';
	printf("%c %s\n", separator, string);
	separator = ',';
}
