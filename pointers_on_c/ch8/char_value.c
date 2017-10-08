#include <stdio.h>

#define SHOW_DEFINE(x) printf("%-20s: 0x%02x %c\n", #x, x, x)

int main(void)
{
	unsigned char char_value[3][6][4][5] = {
		{
			{
				/* [0][0][0] */
				{}, {},
				{}, {},
			},
			{
				{}, {},
				{}, {},
			},
			{
				{}, {},
				{}, {},
			},
			{
				{}, {},
				{}, {},
			},
			{
				{}, {},
				{}, {},
			},
			{
				{}, {},
				{}, {},
			},
		},
		{
			{
				/* [1][0][0] */
				{}, {},
				{}, {},
			},
			{
				{}, {'\0', ' '},
				{}, {},
			},
			{
				{}, {},
				{'\0', '\0', '\0', 'A'}, {'\0', '\0', '\0', '\0', 'X'},
			},
			{
				{}, {},
				{'\0', '\0', 0xf3}, {},
			},
			{
				{}, {},
				{'\0', '\0', '\0', '\n'}, {},
			},
			{
				{}, {},
				{}, {},
			},
		},
		{
			{
				/* [2][0][0] */
				{}, {},
				{}, {},
			},
			{
				{}, {'\0', '\0', 0320},
				{}, {},
			},
			{
				{}, {'\0', '0'},
				{'\0', '\0', '\''}, {'\0', '\121'},
			},
			{
				{}, {},
				{}, {},
			},
			{
				{}, {},
				{}, {'\0', '\0', '3', 3},
			},
			{
				{}, {},
				{}, {'\0', '\0', '\0', '\0', 125},
			},
		},
	};

	SHOW_DEFINE(char_value[1][2][2][3]);
	SHOW_DEFINE(char_value[2][4][3][2]);
	SHOW_DEFINE(char_value[2][4][3][3]);
	SHOW_DEFINE(char_value[2][1][1][2]);
	SHOW_DEFINE(char_value[1][1][1][1]);
	SHOW_DEFINE(char_value[1][4][2][3]);
	SHOW_DEFINE(char_value[2][5][3][4]);
	SHOW_DEFINE(char_value[2][2][2][2]);
	SHOW_DEFINE(char_value[1][3][2][2]);
	SHOW_DEFINE(char_value[2][2][3][1]);
	SHOW_DEFINE(char_value[1][2][3][4]);
	SHOW_DEFINE(char_value[2][2][1][1]);

	return 0;
}
