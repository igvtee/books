#define _GNU_SOURCE
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

#include "config.h"

int main()
{
	int ret;
	char *str = NULL;

	_Static_assert(INT_MAX > 33000L, "Your compiler uses very short integers.");

#ifdef HAVE_STRCASECMP
	strcasecmp("Hello", "world");
#else
	static_assert(0, "HAVE_ASPRINTF undefined. I simply refuse to "
			"compile on a system without asprintf.");
#endif

#ifdef HAVE_ASPRINTF
	ret = asprintf(&str, "%s %s!\n", "Hello", "world");
#else
#error "HAVE_ASPRINTF undefined. I simply refuse to " \
	"compile on a system without asprintf."
#endif

	if (ret == -1)
		return 1;
	free(str);
}
