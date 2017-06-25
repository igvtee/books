#include <stdio.h>
#include <stddef.h>
#include <wchar.h>
#include <string.h>

int main(void)
{
	char c[] = "Hello World";
	wchar_t wc[] = L"Hello World";

	printf("wchar_t size %ld\n", sizeof(wchar_t));
	printf("strlen:%ld, size:%ld, '%s'\n", strlen(c), sizeof(c), c);
	printf("wcslen:%ld, size:%ld, '%ls', '%S'\n", wcslen(wc), sizeof(wc),
	       wc, wc);

	return 0;
}
