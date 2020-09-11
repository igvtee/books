#ifndef __LUA_MYLIB
#define __LUA_MYLIB
#include <lauxlib.h>

int l_sin(lua_State *L);
int l_dir(lua_State *L);
int luaopen_mylib(lua_State *L);
#endif
