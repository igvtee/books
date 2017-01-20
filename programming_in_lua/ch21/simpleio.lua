--[[
io.read
"*all" : reads the whole file
"*line" : reads the next line
"*number" : reads a number
num : reads a string with up to num characters
]]--
io.write("sin (3) = ", math.sin(3), "\n")
--> sin (3) = 0.1411200080598672
io.write(string.format("sin (3) = %.4f\n", math.sin(3)))
--> sin (3) = 0.1411

print("hello", "Lua"); print("Hi")
--> hello Lua
--> Hi
io.write("hello", "Lua"); io.write("Hi", "\n")
--> helloLuaHi

--[[
t = io.read("*all")
t = string.gsub(t, "([\128-\255=])", function (c)
	return string.format("=%02X", string.byte(c))
end)
io.write(t)
]]--

--[[
local count = 1
while true do
	local line = io.read()
	if line == nil then break end
	io.write(string.format("%6d ", count), line, "\n")
	count = count + 1
end
]]--

--[[
local lines = {}
-- read the lines in table 'lines'
for line in io.lines() do
	table.insert(lines, line)
end
-- sort
table.sort(lines)
-- write all the lines
for i, l in ipairs(lines) do io.write(l, "\n") end
]]--

--[[
-- 6.0 -3.23 15e12
-- 4.3 234 1000001
while true do
local n1, n2, n3 = io.read("*number", "*number", "*number")
	if not n1 then break end
	print(math.max(n1, n2, n3))
end

local pat = "(%S+)%s+(%S+)%s+(%S+)%s+"
for n1, n2, n3 in string.gfind(io.read("*all"), pat) do
	print(math.max(n1, n2, n3))
end
]]--

--[[
local size = 2^13 -- good buffer size (8K)
while true do
	local block = io.read(size)
	if not block then break end
	io.write(block)
end
]]--
