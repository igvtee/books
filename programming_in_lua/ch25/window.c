#include <stdio.h>
#include <string.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#define WINCONF	"window.conf"

void load(lua_State *L, const char *fname, int *w, int *h)
{
	if (luaL_loadfile(L, fname) || lua_pcall(L, 0, 0, 0))
		luaL_error(L, "cannot run config. file: %s", lua_tostring(L, -1));
	lua_getglobal(L, "width");
	lua_getglobal(L, "height");
	if (!lua_isnumber(L, -2))
		luaL_error(L, "’width’ should be a number\n");
	if (!lua_isnumber(L, -1))
		luaL_error(L, "’height’ should be a number\n");
	*w = lua_tointeger(L, -2);
	*h = lua_tointeger(L, -1);
}

int main(void)
{
	lua_State *L = luaL_newstate();
	int width, height;
	luaL_openlibs(L);

	load(L, WINCONF, &width, &height);
	printf("width: %d, height %d\n", width, height);

	lua_close(L);
	return 0;
}
