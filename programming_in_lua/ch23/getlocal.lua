--[[
This function has two parameters: the stack level of the function you are
querying and a variable index. It returns two values: the name and the
current value of this variable.
]]--
function foo (a,b)
	local x
	do local c = a - b end
	local a = 1
	while true do
		local name, value = debug.getlocal(1, a)
		if not name then break end
		print(name, value)
		a = a + 1
	end
end

foo(10, 20)
