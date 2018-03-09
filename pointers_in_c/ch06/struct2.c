int main(int argc, char* argv[])
{
	struct date
	{
		int day;
		int month;
		int year;
	};
	struct date current = { 1, 11, 2012 };
	struct date current2 = { .month = 11 };
	current = (struct date){ .year = 2012};
	return 0;
}
