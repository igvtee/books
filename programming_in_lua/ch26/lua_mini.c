#include <stdio.h>
#include <string.h>
#include <lualib.h>
#include "mylib.h"

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
