-- incorrect example
--[[
a = 1			-- create a global variable
-- change current environment to a new empty table
setfenv(1, {})
print(a)			--> attempt to call global 'print' (a nil value)
]]--

-- version 1
--[[
a = 1			-- create a global variable
-- change current environment to a new empty table
setfenv(1, {_G = _G})
_G.print(a)			--> nil
_G.print(_G.a)			--> 1
]]--

-- version 2
a = 1
local newgt = {}			-- create new environment
setmetatable(newgt, {__index = _G})
setfenv(1, newgt)			-- set it
print(a)			--> 1

-- continue previous code
a = 10
print(a)			--> 10
print(_G.a)			--> 1
_G.a = 20
print(_G.a)			--> 20
