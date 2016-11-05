#ifndef __MINI_CRT_H__
#define __MINI_CRT_H__

// malloc.c
#ifndef NULL
#define NULL	(0)
#endif

void free(void * ptr);
void * malloc(unsigned size);
int mini_crt_heap_init(void);

// stdio.c
typedef int FILE;

#define EOF	(-1)

#define stdin	((FILE *)0)
#define stdout	((FILE *)1)
#define stderr	((FILE *)2)

int mini_crt_io_init(void);
FILE * fopen(const char * filename, const char * mode);
int fread(void * buffer, int size, int count, FILE * stream);
int fwrite(const void * buffer, int size, int count, FILE * stream);
int fclose(FILE *fp);
int fseek(FILE * fp, int offset, int set);

// string.c
char * itoa(int n, char * str, int radix);
int strcmp( const char * src, const char * dst);
char * strcpy(char *dest, const char * src);
int strlen(const char *str);

// printf.c
int fputc(int c, FILE * STREAM);
int fputs(const char * str, FILE * stream);
int printf(const char * format, ...);
int fprintf(FILE * stream, const char * format, ...);

#endif // __MINI_CRT_H__
