-- print(package.loadlib())

local path = "/usr/local/lua/lib/libuasocket.so"
local f = assert(package.loadlib(path, "luaopen_socket"))
f()		-- actually open the library
