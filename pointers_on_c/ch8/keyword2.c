#include <string.h>
#include <stdio.h>

int lookup_keyword( char const * const desired_word,
		    char const (*keyword_table)[9], int const size )
{
	char	const (*kwp)[9];

	/*
	 ** For each word in the table ...
	 */
	for( kwp = keyword_table; kwp < keyword_table + size; kwp++ )
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


char const keyword[][9] = {
	"do",
	"for",
	"if",
	"register",
	"return",
	"switch",
	"while"
};
#define N_KEYWORD (sizeof(keyword) / sizeof(keyword[0]))

int main(void)
{
	int ret;

	ret = lookup_keyword("return", keyword, N_KEYWORD);
	printf("return: %d\n", ret);

	return 0;
}
