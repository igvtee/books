#include <stdio.h>
#include <string.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#define WINCONF	"ctable.conf"
#define MAX_COLOR	255

struct ColorTable {
	char *name;
	unsigned char red, green, blue;
} colortable[] = {
	{"WHITE", MAX_COLOR, MAX_COLOR, MAX_COLOR},
	{"RED", MAX_COLOR, 0, 0},
	{"GREEN", 0, MAX_COLOR, 0},
	{"BLUE", 0, 0, MAX_COLOR},
	{"BLACK", 0, 0, 0},
	{NULL, 0, 0, 0},	/* sentinel */
};

/* assume that table is at the top */
void setfield(lua_State *L, const char *index, int value)
{
	lua_pushstring(L, index);
	lua_pushnumber(L, (double)value/MAX_COLOR);
	lua_settable(L, -3);
}

void setcolor(lua_State *L, struct ColorTable *ct)
{
	lua_newtable(L);	/* create a table */
	setfield(L, "r", ct->red);	/* table.r = ct->r */
	setfield(L, "g", ct->green);	/* table.g = ct->g */
	setfield(L, "b", ct->blue);	/* table.b = ct->b */
	lua_setglobal(L, ct->name);	/* 'name' = table */
}

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
		luaL_error(L, "cannot run config. file: %s",
				lua_tostring(L, -1));

	lua_getglobal(L, "background");
	if (lua_isstring(L, -1)) {
		const char *name = lua_tostring(L, -1);
		int i;
		for (i = 0; colortable[i].name != NULL; i++) {
			if (strcmp(name, colortable[i].name) == 0)
				break;
		}
		if (colortable[i].name == NULL)
			luaL_error(L, "invalid color name (%s)", name);
		else {
			*red = colortable[i].red;
			*green = colortable[i].green;
			*blue = colortable[i].blue;
		}
	} else if (lua_istable(L, -1)) {
		*red = getfield(L, "r");
		*green = getfield(L, "g");
		*blue = getfield(L, "b");
	} else
		luaL_error(L, "'background' is not a valid color table");
}

int main(void)
{
	lua_State *L = luaL_newstate();
	int red, green, blue;
	luaL_openlibs(L);
	int i = 0;

	while (colortable[i].name != NULL)
		setcolor(L, &colortable[i++]);

	load(L, WINCONF, &red, &green, &blue);
	printf("red: %d, green: %d, blue: %d\n", red, green, blue);

	lua_close(L);
	return 0;
}
