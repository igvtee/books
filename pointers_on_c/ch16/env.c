#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *env = "key";
	char *val = "value";
	char buf[64];

	snprintf(buf, sizeof(buf), "%s=%s", env, val);
	putenv(buf);

	val = getenv(env);
	if (val)
		printf("key : %s\n", val);

	return 0;
}
