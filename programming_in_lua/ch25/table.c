#include <stdio.h>
#include <string.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#define WINCONF	"table.conf"
#define MAX_COLOR	255

/* assume that table is on the stack top */
int getfield(lua_State *L, const char *key)
{
	int result;

	lua_pushstring(L, key);
	lua_gettable(L, -2);	/* get background[key] */
	if (!lua_isnumber(L, -1))
		luaL_error(L, "invalid component in background color");
	result = (int)lua_tonumber(L, -1) * MAX_COLOR;
	lua_pop(L, 1);	/* remove number */

	return result;
}

void load(lua_State *L, const char *fname, int *red, int *green, int *blue)
{
	if (luaL_loadfile(L, fname) || lua_pcall(L, 0, 0, 0))
		luaL_error(L, "cannot run config. file: %s", lua_tostring(L, -1));

	lua_getglobal(L, "background");
	if (!lua_istable(L, -1))
		luaL_error(L, "'background' is not a valid color table");
	*red = getfield(L, "r");
	*green = getfield(L, "g");
	*blue = getfield(L, "b");
}

int main(void)
{
	lua_State *L = luaL_newstate();
	int red, green, blue;
	luaL_openlibs(L);

	load(L, WINCONF, &red, &green, &blue);
	printf("red: %d, green: %d, blue: %d\n", red, green, blue);

	lua_close(L);
	return 0;
}
