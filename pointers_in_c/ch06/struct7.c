#include <stdio.h>
#include <malloc.h>
int main(int argc, char* argv[])
{
	struct gif_hdr
	{
		char signature[3];
		char version[3];
		int width;
		int height;
		char colormap;
		char bgcolor;
		char ratio;
	};
	struct gif_hdr *dsptr;
	printf("Size of structure data = %zu\n", sizeof(struct gif_hdr));
	dsptr = (struct gif_hdr*)malloc(sizeof(struct gif_hdr));
	printf("Offset of signature = %td\n", &(dsptr->signature[0]) - &(dsptr->signature[0]) );
	printf("Offset of version = %td\n", &(dsptr->version[0]) - &(dsptr->signature[0]) );
	printf("Offset of width = %td\n", (char*)&(dsptr->width) - &(dsptr->signature[0]));
	printf("Offset of height = %td\n", (char*)&(dsptr->height) - &(dsptr->signature[0]));
	printf("Offset of colormap = %td\n", &(dsptr->colormap) - &(dsptr->signature[0]));
	printf("Offset of bgcolor = %td\n",&(dsptr->bgcolor) - &(dsptr->signature[0]));
	printf("Offset of ratio = %td\n", &(dsptr->ratio) - &(dsptr->signature[0]));
	return 0;
}
