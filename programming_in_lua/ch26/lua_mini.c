#include <stdio.h>
#include <string.h>
#include <math.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

static int l_sin(lua_State *L)
{
	//double d = lua_tonumber(L, 1);	/* get argument */
	double d = luaL_checknumber(L, 1);	/* get argument */
	lua_pushnumber(L, sin(d));	/* push result */
	return 1;	/* number of results */
}

static int l_dir(lua_State *L)
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
		lua_pushnumber(L, i++);	/* push key */
		lua_pushstring(L, entry->d_name);	/* push value */
		lua_settable(L, -3);
	}

	/* posible memory leak if lua_pushnumber, lua_pushstring or lua_settable
	 * failed
	 */
	closedir(dir);
	return 1;	/* table is already on top */
}

int main (void) {
	char buff[256];
	int error;
	lua_State *L = luaL_newstate(); /* opens Lua */
	luaL_openlibs(L); /* opens the standard libraries */

	/* register c function into lua */
	lua_pushcfunction(L, l_sin);
	lua_setglobal(L, "mysin");
	lua_pushcfunction(L, l_dir);
	lua_setglobal(L, "mydir");

	while (fgets(buff, sizeof(buff), stdin) != NULL) {
		error = luaL_loadbuffer(L, buff, strlen(buff), "line") ||
			lua_pcall(L, 0, 0, 0);
		if (error) {
			fprintf(stderr, "%s", lua_tostring(L, -1));
			lua_pop(L, 1); /* pop error message from the stack */
		}
	}

	lua_close(L);
	return 0;
}
