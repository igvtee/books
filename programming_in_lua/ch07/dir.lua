local f = io.popen("ls", "r")
local dir = {}
for entry in f:lines() do
	dir[#dir + 1] = entry
end
