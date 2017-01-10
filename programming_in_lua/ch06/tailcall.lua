-- because tail call use no stack space. it will never overflow the stack
-- like goto
function foo (n)
	if n > 0 then 
		return foo(n-1)
	end
end
foo(1000)

-- not tail call
function f (x)
	foo(x)
	return
end
--[[
return f(x) + 1
return x or g(x)
return (g(x))
]]--

-- is tail call
--[[
return x[i].foo(x[j] + a*b, i+j)
]]--
