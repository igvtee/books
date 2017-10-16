#include <stdio.h>

struct DISK_REGISTER_FORMAT {
	unsigned command	: 5;
	unsigned sector		: 5;
	unsigned track		: 9;
	unsigned error_code	: 8;
	unsigned head_loaded	: 1;
	unsigned write_protect	: 1;
	unsigned disk_spinning	: 1;
	unsigned error_occurred : 1;
	unsigned ready		: 1;
};

#define DISK_REGISTER \
	((struct DISK_REGISTER_FORMAT *)0xc0200142)

int main(void)
{
	DISK_REGISTER->sector = new_sector;
	DISK_REGISTER->track = new_track;
	DISK_REGISTER->command = READ;

	while (!DISK_REGISTER->READY)
		;

	return 0;
}
