#include <stdio.h>

void deblank(char string[])
{
	char *src = string;
	char *dst = string;

	while (*src) {
		switch (*src) {
		case ' ':
			/* skip duplicate */
			if (src != string && src[-1] == ' ') {
				break;
			}
			/* add entry by default */
		default:
			if (dst != src)
				*dst = *src;
			dst++;
			break;
		}
		src++;
	}
	*dst = '\0';
}

int main(void)
{
	char buf[128] = "   Hello    world !  ";

	printf("'%s'\n", buf);
	deblank(buf);
	printf("'%s'\n", buf);

	return 0;
}
