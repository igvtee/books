function declare (name, initval)
	rawset(_G, name, initval or false)
end

setmetatable(_G, {
	__newindex = function (_, n)
		error("attempt to write to undeclared variable " .. n, 2)
	end,
	__index = function (_, n)
		error("attempt to read undeclared variable " .. n, 2)
	end,
})
-- a = 1			--> attempt to write to undeclared variable a

declare("a", 3)
print(a)
a = 1
print(a)

if rawget (_G, "avr") == nil then
	print("'var' is undeclared")
end
