int current_element = 0;
int total_element = 128;
char *dynamic = malloc(total_element);

void add_element(char c)
{
	if (current_element == total_element - 1) {
		total_element *= 2;
		dynamic = (char *) realloc(dynamic, total_element);
		if (dynamic == NULL)
			error("Coundn't expand the table");
	}
	current_element++;
	dynamic[current_element] = c;
}
