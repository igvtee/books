#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#define CONF	"fun.lua"

void call_va(lua_State *L, const char *func, const char *sig, ...)
{
	va_list vl;
	int narg, nres;	/* number of arguments and results */

	va_start(vl, sig);
	lua_getglobal(L, func);	/* get function */

	/* push arguments */
	narg = 0;
	while (*sig) {
		switch (*sig++) {
		case 'd':	/* double argument */
			lua_pushnumber(L, va_arg(vl, double));
			break;
		case 'i':	/* int argument */
			lua_pushnumber(L, va_arg(vl, int));
			break;
		case 's':	/* string argument */
			lua_pushstring(L, va_arg(vl, char *));
			break;
		case '>':
			goto endwhile;
		default:
			luaL_error(L, "invalid option (%c)", *(sig-1));
		}
		narg++;
		luaL_checkstack(L, 1, "too many arguments");
	}

endwhile:
	/* do the call */
	nres = strlen(sig);	/* number of expected results */
	if (lua_pcall(L, narg, nres, 0) != 0)
		luaL_error(L, "error running function '%s': %s", func,
				lua_tostring(L, -1));

	/* retrieve results */
	nres = -nres;	/* stack index of first result */
	while (*sig) {
		switch (*sig++) {
		case 'd':	/* double result */
			if (!lua_isnumber(L, nres))
				luaL_error(L, "wrong result type");
			*va_arg(vl, double *) = lua_tonumber(L, nres);
			break;
		case 'i':	/* int argument */
			if (!lua_isnumber(L, nres))
				luaL_error(L, "wrong result type");
			*va_arg(vl, int *) = (int)lua_tonumber(L, nres);
			break;
		case 's':	/* string argument */
			if (!lua_isstring(L, nres))
				luaL_error(L, "wrong result type");
			*va_arg(vl, const char **) = lua_tostring(L, nres);
			break;
		default:
			luaL_error(L, "invalid option (%c)", *(sig-1));
		}
		nres++;
	}
	va_end(vl);
}

int main(void)
{
	double res;
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);

	if (luaL_loadfile(L, CONF) || lua_pcall(L, 0, 0, 0))
		luaL_error(L, "cannot run config. file: %s",
				lua_tostring(L, -1));
	call_va(L, "f", "dd>d", 3.0, 4.0, &res);
	printf("result: %lf\n", res);

	lua_close(L);
	return 0;
}
