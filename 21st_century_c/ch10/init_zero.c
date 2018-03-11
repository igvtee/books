#include <string.h>

typedef struct {
	int la, de, da;
} ladeda_s;

int main()
{
	ladeda_s emptystruct = {};
	int ll[20] = {};

	/* variable-length array only init to zero via memset */
	int length = 20;
	int bb[length];
	memset(bb, 0, 20*sizeof(int));
}
