#include <lua.h>

typedef struct NumArray {
	int size;
	double values[1];	/* variable part */
} NumArray;

static int newarray (lua_State *L) {
	int n = luaL_checkint(L, 1);
	size_t nbytes = sizeof(NumArray) + (n - 1) * sizeof(double);
	NumArray *a = (NumArray *)lua_newuserdata(L, nbytes);
	a->size = n;
	return 1;
}
