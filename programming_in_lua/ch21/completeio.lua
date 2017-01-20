--[[
io.stdin, io.stdout, io.stderr
]]--

filename = "completeio.lua"
local f = assert(io.open(filename, "r"))
local t = f:read("*all")
f:close()

io.stderr:write("io.stderr output\n")

--[[
local temp = io.input()	-- save current file
io.input("newinput")	-- open a new current file
...						-- do something with new input
io.input():close()		-- close current file
io.input(temp)			-- restore previous current file
]]--
