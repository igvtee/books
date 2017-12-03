#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>

/* Convert the source file timestamp into a localized data string */
char * localized_time(char *filename)
{
	struct tm *tm_ptr;
	struct stat stat_block;
	char buffer[120];

	/* get the sourcefile's timestamp in time_t format */
	stat(filename, &stat_block);

	/* convert UNIX time_t into a struct tm holding local time */
	tm_ptr = localtime(&stat_block.st_mtime);

	/* convert the tm struct into a string in llocal format */
	strftime(buffer, sizeof(buffer), "%a %b %e %T %Y", tm_ptr);

	return buffer;
}

int main(int argc, char **argv)
{
	char *time;

	time = localized_time(argv[0]);
	printf("%s\n", time);

	return 0;
}
