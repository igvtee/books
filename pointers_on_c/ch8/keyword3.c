/*
** Determine whether the argument matches any of the words in
** a list of keywords, and return the index to the one it matches.
** If no match is found, return the value -1.
*/

#include <string.h>
#include <stdio.h>

int
lookup_keyword( char const * const desired_word,
    char const *keyword_table[], int const size )
{
	char	const **kwp;

	/*
	** For each word in the table ...
	*/
	for( kwp = keyword_table; *kwp != NULL; kwp++ )
		/*
		** If this word matches the one we're looking for,
		** return its position in the table.
		*/
		if( strcmp( desired_word, *kwp ) == 0 )
			return kwp - keyword_table;

	/*
	** Not found.
	*/
	return -1;
}

char const *keyword[] = {
	"do",
	"for",
	"if",
	"register",
	"return",
	"switch",
	"while",
	NULL
};
#define N_KEYWORD (sizeof(keyword) / sizeof(keyword[0]))

int main(void)
{
	int ret;

	ret = lookup_keyword("return", keyword, N_KEYWORD);
	printf("return: %d\n", ret);

	return 0;
}
