#include <stdio.h>
#include <malloc.h>

int main(void) {
        int *p = NULL;

        p = malloc(10 * sizeof(int));
        free(p);
        *p = 3;
        return 0;
}
