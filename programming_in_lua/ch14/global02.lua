local declaredNames = {}
function declare (name, initval)
	rawset(_G, name, initval or false)
	declaredNames[name] = true
end

setmetatable(_G, {
	__newindex = function (_, n)
		if not declaredNames[n] then
			error("attempt to write to undeclared variable " .. n, 2)
		else
			rawset(t, n, v)			-- do the actual set
		end
	end,
	__index = function (_, n)
		if not declaredNames[n] then
			error("attempt to read undeclared variable " .. n, 2)
		else
			return nil
		end
	end,
})
-- a = 1			--> attempt to write to undeclared variable a

declare("a", 3)
print(a)
a = nil 
print(a)

if a == nil then
	print("'var' is nil")
end
