/* isupper: return 1 (true) if c is an upper case letter */

/* save space version */
int isupper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return 1;
	else
		return 0;
}

/* save time version */
#define isupper(c)	((c) >= 'A' && (c) <= 'Z') ? 1 : 0
