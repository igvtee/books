#include <stdio.h>
#include <stdlib.h>
#include <utils.h>
#include <string.h>

__constructor void main_constructor(void)
{
	printf("--- %s ---\n", __func__);
}

__destructor void main_destructor(void)
{
	printf("--- %s ---\n", __func__);
}

__hidden void hidden_function(void)
{
	printf("--- %s ---\n", __func__);
}

int main(void)
{
	int size[3] = {10, 2, 8};
	void *buf[3];
	const char *text = "abc!@#";
	char *tmp;
	unsigned int i;

	/* calloc_a */
	buf[0] = calloc_a(size[0], &buf[1], size[1], &buf[2], size[2]);
	printf("calloc_a align size: %zu\n", sizeof(size_t));
	for (i = 0; i < ARRAY_SIZE(size); i++)
		printf("	size: %2d, addr: %p\n", size[i], buf[i]);

	/* __BUILD_BUG_ON */
	__BUILD_BUG_ON(ARRAY_SIZE(size) == 0);

	/* __BYTE_ORDER */
#if __BYTE_ORDER == __LITTLE_ENDIAN
	printf("byte order little endian\n");
#elif __BYTE_ORDER == __BIG_ENDIAN
	printf("byte order big endian\n");
#else
#error unknown byte order
#endif

	/* __is_constant */
	printf("'1' constant is: %d\n", __is_constant(1));
	printf("'buf' constant is: %d\n", __is_constant(buf));

	/* byte convert */
	printf("cpu_to_le32: %08x\n", cpu_to_le32(size[1]));
	printf("cpu_to_be32: %08x\n", cpu_to_be32(size[1]));

	hidden_function();

	/* base64 */
	i = B64_ENCODE_LEN(strlen(text));
	tmp = malloc(i);
	b64_encode(text, strlen(text), tmp, i);
	printf("base64 '%s':%zu encode to '%s':%d\n", text, strlen(text),
	       tmp, i);
	free(tmp);

	return 0;
}
