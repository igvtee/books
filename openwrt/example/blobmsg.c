#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <blobmsg_json.h>

int main(void)
{
	struct blob_buf buf = {0};
	struct blob_attr *cur;
	uint64_t value = 0x1234567890ULL;
	unsigned int rem;
	char *cbuf;

	blobmsg_buf_init(&buf);

	blobmsg_add_u64(&buf, "u64", value++);
	blobmsg_add_u64(&buf, "u64", value++);
	blobmsg_add_u64(&buf, "u64", value++);

	blobmsg_for_each_attr(cur, buf.head, rem) {
		value = blobmsg_get_u64(cur);
		printf("name: %s, value:%"PRIx64"\n", blobmsg_name(cur), value);
	}

	cbuf = blobmsg_format_json(buf.head, true);
	printf("%s\n", cbuf);
	free(cbuf);

	cbuf = blobmsg_format_json(blobmsg_data(buf.head), false);
	printf("%s\n", cbuf);
	free(cbuf);

	cbuf = blobmsg_format_json_value(blobmsg_data(buf.head));
	printf("%s\n", cbuf);
	free(cbuf);

	blob_buf_free(&buf);

	return 0;
}
