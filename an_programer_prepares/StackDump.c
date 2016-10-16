#include <stdio.h>
#include <elf.h>

int main(int argc, char * argv[])
{
	int * p= (int *)argv;
	int i;
	Elf32_auxv_t * aux;

	printf("Argument count: %d\n", *(p - 1));

	for (i = 0; i < *(p - 1); i++)
		printf("Argument %d : %s\n", i, (char *)*(p + i));

	p += i;
	p++; // skip 0

	printf("\nEnvironment:\n");
	while (*p) {
		printf("%s\n", (char *)*p);
		p++;
	}

	p++; // skip 0

	printf("\nAuxiliary Vectors:\n");
	aux = (Elf32_auxv_t *)p;
	while (aux->a_type != AT_NULL) {
		printf("Type: %02d, Value: %x\n", aux->a_type, aux->a_un.a_val);
		aux++;
	}

	return 0;
}
