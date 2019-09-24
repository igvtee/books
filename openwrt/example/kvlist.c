#include <stdio.h>
#include <stdlib.h>
#include <kvlist.h>

int main(void)
{
	int i;
	char key[] = "keyX";
	char value[] = "valueX";
	const char *pkey, *pvalue;
	KVLIST(kv, kvlist_strlen);

	for (i = 0; i < 10; i++) {
		key[3] = '0' + i;
		value[5] = '0' + i;
		kvlist_set(&kv, key, value);
	}

	kvlist_for_each(&kv, pkey, pvalue)
		printf("%s: %s\n", pkey, pvalue);

	key[3] = '4';
	pkey = key;
	pvalue = kvlist_get(&kv, pkey);
	if (pvalue) {
		printf("get %s: %s\n", pkey, pvalue);
		kvlist_delete(&kv, pkey);
	}

	kvlist_free(&kv);

	return 0;
}
