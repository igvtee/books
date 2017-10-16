#include <stdio.h>
#include <string.h>
#include <ctype.h>

int prepare_key(char *key)
{
	char buf[27];
	char *pbuf = buf;
	char *pkey = key;
	unsigned int bits = 0;
	int offset;

	while (*pkey) {
		if (!isalpha(*pkey))
			return -1;
		*pkey = toupper(*pkey);
		offset = *pkey - 'A';
		if ((bits & (0x1 << offset)) == 0) {
			bits |= (0x1 << offset);
			*pbuf++ = *pkey;
		}
		pkey++;
	}

	offset = 0;
	while (offset < 26) {
		if ((bits & (0x1 << offset)) == 0)
			*pbuf++ = 'A' + offset;
		offset++;
	}
	*pbuf = '\0';

	strcpy(key, buf);

	return 0;
}

void encrypt(char *data, char const *key)
{
	while (*data) {
		if (isupper(*data))
			*data = key[toupper(*data) - 'A'];
		else if (islower(*data))
			*data = 'a' + (key[toupper(*data) - 'A'] - 'A');
		data++;
	}
}

void decrypt(char *data, char const *key)
{
	char *pkey;

	while (*data) {
		if (isupper(*data)) {
			pkey = strchr(key, *data);
			if (pkey)
				*data = 'A' + (pkey - key);
		} else if (islower(*data)) {
			pkey = strchr(key, toupper(*data));
			if (pkey)
				*data = 'a' + (pkey - key);
		}
		data++;
	}
}

int main(void)
{
	char key[27] = "TRAILBLAZERS";
	char data[] = "Attack at dawn";
	int ret;

	if (prepare_key(key)) {
		printf("invalid key: %s\n", key);
		return 1;
	}

	encrypt(data, key);
	printf("encrypt: '%s'\n", data);
	decrypt(data, key);
	printf("decrypt: '%s'\n", data);

	return 0;
}
