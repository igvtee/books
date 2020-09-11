#include <math.h>
#include <sys/types.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <lua.h>
#include "mylib.h"

int l_sin(lua_State *L)
{
	//double d = lua_tonumber(L, 1);	/* get argument */
	double d = luaL_checknumber(L, 1);	/* get argument */
	lua_pushnumber(L, sin(d));	/* push result */
	return 1;	/* number of results */
}

int l_dir(lua_State *L)
{
	DIR *dir;
	struct dirent *entry;
	int i;
	const char *path = luaL_checkstring(L, 1);

	/* open directory */
	dir = opendir(path);
	if (dir == NULL) {	/* error opening the directory? */
		lua_pushnil(L);	/* return nil and ... */
		lua_pushstring(L, strerror(errno));	/* error message */
		return 2;	/* number of results */
	}

	/* create result table */
	lua_newtable(L);
	i = 1;
	while ((entry = readdir(dir)) != NULL) {
#if 1
		lua_pushstring(L, entry->d_name);	/* value */
		lua_rawseti(L, -2, i++);		/* set table at key 'i' */
#else
		lua_pushnumber(L, i++);	/* push key */
		lua_pushstring(L, entry->d_name);	/* push value */
		lua_settable(L, -3);
#endif
	}

	/* posible memory leak if lua_pushnumber, lua_pushstring or lua_settable
	 * failed
	 */
	closedir(dir);
	return 1;	/* table is already on top */
}

static const struct luaL_reg mylib[] = {
	{"sin", l_sin},
	{"dir", l_dir},
	{NULL, NULL}
};

int luaopen_mylib(lua_State *L) {
	luaL_openlib(L, "mylib", mylib, 0);
	return 1;
}
