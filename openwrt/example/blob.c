#include <stdio.h>
#include <blob.h>

#define ATTR_MAX 10

static bool str_validate(const struct blob_attr_info *info __attribute__((unused)),
			 struct blob_attr *pos)
{
	printf("%s id:%2d len:%2d data:%s\n", __func__, blob_id(pos),
	       blob_len(pos), pos->data);
	return 1;
}

int main(void)
{
	struct blob_buf blob = {0};
	int id = 0, i;
	void *cookie;
	struct blob_attr *pos;
	unsigned int rem;
	struct blob_attr *attrs[ATTR_MAX];
	struct blob_attr_info info[ATTR_MAX] = {{0}, {0},
		{BLOB_ATTR_STRING, 2, 5, str_validate}};

	blob_buf_init(&blob, id++);
	blob_put(&blob, id++, "this", strlen("this")+1);
	blob_put(&blob, id++, "book", strlen("book")+1);

	blob_for_each_attr(pos, blob.head, rem)
		printf("id:%2d len:%2d data:%s\n", blob_id(pos), blob_len(pos),
		       pos->data);
	putchar('\n');

	cookie = blob_nest_start(&blob, id++);
	blob_put(&blob, id++, "that", strlen("that")+1);
	blob_put(&blob, id++, "tree", strlen("tree")+1);
	blob_for_each_attr(pos, blob.head, rem)
		printf("id:%2d len:%2d data:%s\n", blob_id(pos), blob_len(pos),
		       pos->data);
	putchar('\n');
	blob_nest_end(&blob, cookie);

	blob_for_each_attr(pos, blob.head, rem)
		printf("id:%2d len:%2d data:%s\n", blob_id(pos), blob_len(pos),
		       pos->data);
	putchar('\n');

	blob_parse(blob.head, &attrs[0], info, ARRAY_SIZE(attrs));
	for (i = 0; i < ATTR_MAX; i++) {
		pos = attrs[i];
		if (!pos)
			continue;
		printf("id:%2d len:%2d data:%s\n", blob_id(pos), blob_len(pos),
		       pos->data);
	}
	putchar('\n');

	if (blob_attr_equal(attrs[1], attrs[2]))
		printf("blob id %d equal %d\n", blob_id(attrs[1]),
		       blob_id(attrs[2]));
	else
		printf("blob id %d not equal %d\n", blob_id(attrs[1]),
		       blob_id(attrs[2]));
	putchar('\n');

	pos = blob_memdup(attrs[1]);
	blob_put_raw(&blob, pos, blob_pad_len(pos));
	free(pos);
	blob_for_each_attr(pos, blob.head, rem)
		printf("id:%2d len:%2d data:%s rem:%u\n", blob_id(pos), blob_len(pos),
		       pos->data, rem);
	putchar('\n');

	blob_buf_free(&blob);

	return 0;
}
