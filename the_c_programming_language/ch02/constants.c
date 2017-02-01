#include <stdio.h>

/*
 * integer constants *
 * long :	l or L
 * unsigned :	u or U
 * double :	123.4 or 1e-2
 * float :	f or F
 * octal :	037
 * hex :	0x1f or 0X1f
 */

/*
 * character constants *
 * char :	'x'
 * octal :	'\123'
 * hex :	'\x0'
 *
 * escape sequences *
 * \a	alert (bell)		\\	backslash
 * \b	backspace		\?	question mark
 * \f	formfeed		\'	single quote
 * \n	newline			\"	double quote
 * \r	carriage return		\ooo	octal number
 * \t	horizontal tab		\xhh	hexadecimal number
 * \v	vertical tab
 */

main()
{
	putchar('\a');
}
