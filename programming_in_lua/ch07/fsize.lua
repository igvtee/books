function fsize(file)
	local current = file:seek()
	local size = file:seek("end")
	file:seek("set", current)
	return size
end

local f = io.open("fsize.lua", "r")
print(fsize(f))
io.close(f)
