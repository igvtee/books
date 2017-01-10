print "Hello World"		-->	print("Hello World")
print [[a multi-lin 
message]]
--[[
dofile 'a.lua'	-->	dofile('a.lua')
f{x=10, y=20}	--> f({x=10, y=20})
]]--
print(type{})			--> type({})

s, e = string.find("hello Lua users", "Lua")	--> 7	9
print(s, e)

function maximum(a)
	local mi = 1
	local m = a[mi]
	for i,val in ipairs(a) do
		if val > m then
			mi = i
			m = val
		end
	end
	return m, mi
end

print(maximum({8, 10, 23, 12, 5}))	--> 23	3

function foo0()
end
function foo1()
	return 'a'
end
function foo2()
	return 'a', 'b'
end
x, y, z = 10, foo2()	-->	x=10, y='a', z='b'
print(x, y, z)

print(foo0())		--> 
print(foo1())		-->	a
print(foo2())		--> a	b
print(foo2(), 1)	-->	a	1
print(foo2() .. "x")	-->	ax

a = {foo0()}		-->	a = {}
a = {foo1()}		--> a = {'a'}
a = {foo2()}		--> a = {'a', 'b'}
a = {foo0(), foo2(), 4}	--> a = {[1]=nil, [2]='a', [3]=4}

function foo(i)
	if i == 0 then
		return foo0();
	elseif i == 1 then
		return foo1()
	elseif i == 2 then
		return foo2()
	end
end
print(foo(1))	-->	a
print(foo(2))	-->	a	b
print(foo(0))	--> (no results)
print(foo(3))	--> (no results)

print((foo(0)))	--> nil
print((foo(1)))	-->	a
print((foo(2)))	-->	a

f = string.find
a = {"hello", "ll"}
print(f(unpack(a)))	-->	3	4
--[[
function unpack(t, i)
	i = i or 1
	if t[i] then
		return t[i], unpack(t, i+1)
	end
end
]]--
