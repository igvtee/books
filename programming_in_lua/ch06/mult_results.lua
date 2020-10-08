s, e = string.find("Hello Lua users", "Lua")
print(s, e)

function maximum(a)
	local mi = 1
	local m = a[mi]
	for i = 1, #a do
		if a[i] > m then
			mi = i; m = a[i]
		end
	end
	return m, mi
end
print(maximum({8, 10, 23, 12, 5}))

function foo0() end
function foo1() return "a" end
function foo2() return "a", "b" end
x, y = foo2()
x = foo2()
x, y, z = 10, foo2()

x, y = foo0()
x, y = foo1()
x, y = foo2()

x, y = foo2(), 20
print(x, y)
x, y = foo0(), 20, 30
print(x, y)

print(foo0())
print(foo1())
print(foo2())
print(foo2(), 1)
print(foo2() .. "x")

t = {foo0()}
print(#t)
t = {foo1()}
print(#t)
t = {foo2()}
print(#t)
t = {foo0(), foo2(), 4}
print(#t)

function foo(i)
	if i == 0 then return foo0()
	elseif i == 1 then return foo1()
	elseif i == 2 then return foo2()
	end
end
print(foo(1))
print(foo(2))
print(foo(0))
print(foo(3))

print((foo(0)))
print((foo(1)))
print((foo(2)))
