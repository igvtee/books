function add(...)
	local s = 0
	for _, v in ipairs({...}) do
		s = s + v
	end
	return s
end

print(add(3, 4, 10, 25, 12))

-- function foo(a, b, c)
function foo(...)
	local a, b, c = ...
end

function foo1(...)
	print("calling foo:", ...)
	foo(...)
end
print(foo1(1, 2, 3))

function fwrite(fmt, ...)
	return io.write(string.format(fmt, ...))
end

--[[
function nonils(...)
	local arg = table.pack(...)
	for i = 1, arg.n do
		if arg[i] == nil then return false end
	end
	return true
end

print(nonils(2, 3, nil))
print(nonils(2, 3))
print(nonils())
print(nonils(nil))
--]]

print(select(1, "a", "b", "c"))
print(select(2, "a", "b", "c"))
print(select(3, "a", "b", "c"))
print(select("#", "a", "b", "c"))

function add(...)
	local s = 0
	for i = 1, select("#", ...) do
		s = s + select(i, ...)
	end
	return s
end
print(add(1, 2, 3))
