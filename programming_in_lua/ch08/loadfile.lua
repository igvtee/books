function dofile (filename)
	-- loadfile will compile the code
	local f = assert(loadfile(filename))
	-- execute it
	return f()
end

-- like loadfile it's a chunk
--[[
loadstring("i = i + 1")
is roughly equivalent to
function () i = i + 1 end
]]--
f = loadstring("i = i + 1")
i = 0
f(); print(i)	--> 1
f(); print(i)	--> 2

i = 32
local i = 0
f = loadstring("i = i + 1; print(i)")
g = function () i = i + 1; print(i) end
f()		-->	33
g()		--> 1

f = loadstring("local a = 10; return a + 20")
print(f())		--> 30

-- nil     [string "i i"]:1: '=' expected near 'i'
print(loadstring("i i"))

f = loadfile("foo.lua")
f()				-- defines 'foo'
foo("ok")		--> ok

-- load and execute
loadstring("print('aa')")()
-- exit with error message
-- assert(loadstring("i i"))()

print("enter your expression:")
local l = io.read()
local func = assert(loadstring("return " .. l))
print("the value of your expression is " .. func())

print("enter function to be plotted (with variable 'x')")
local l = io.read()
local f = assert(loadstring("local x = ...; print(x); return " .. l))
for i=1, 4 do
	print(string.rep("*", f(i)))
end
