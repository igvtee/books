Lib = {}
Lib.foo = function (x, y) return x + y end
Lib.bar = function (x, y) return x - y end
print(Lib.foo(1, 2))

Lib = {
	foo = function (x, y) return x + y end,
	bar = function (x, y) return x - y end
}
print(Lib.foo(1, 2))

Lib = {}
function Lib.foo (x, y) return x + y end
function Lib.bar (x, y) return x - y end
print(Lib.foo(1, 2))

local f = function ()
	print("f")
end
local g = function ()
	print("g")
	f()
end
g()

local fact
fact = function (n)
	if n == 0 then
		return 1
	else
		return n*fact(n-1)
	end
end
print(fact(3))

local f, g			-- 'forward' declarations
function g ()
	f()
end
function f ()
	g()
end
