print(io.open("non-existent-file", "r"))
print(io.open("/etc/passwd", "w"))

local f = assert(io.open("ioopen.lua", "r"))
local t = f:read("*a")
f:close()

io.stderr:write("stderr message\n")
