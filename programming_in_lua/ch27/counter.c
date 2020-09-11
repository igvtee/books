#include <lualib.h>

static int counter(lua_State *L) {
	double val = lua_tonumber(L, lua_upvalueindex(1));
	lua_pushnumber(L, ++val);	/* new value */
	lua_pushvalue(L, -1);		/* duplicate it */
	lua_replace(L, lua_upvalueindex(1));	/* update upvalue */
	return 1;	/* return new value */
}

int newCounter(lua_State *L) {
	lua_pushnumber(L, 0);
	lua_pushcclosure(L, &counter, 1);
	return 1;
}
