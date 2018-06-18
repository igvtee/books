#include <stdio.h>

int main(void)
{
	int ch = 'b';

	switch (ch) {
	case '0' ... '9':
		ch -= '0';
		break;
	case 'a' ... 'f':
		ch -= 'a' - 10;
		break;
	case 'A' ... 'F':
		ch -= 'A' - 10;
		break;
	}
}
