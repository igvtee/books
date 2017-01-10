function add(...)
	local s = 0
	for i, v in ipairs{...} do
		s = s + v
	end
	return s
end
print(add(3, 4, 10, 25, 12))	-->	54


--function foo(a, b, c)
function foo(...)
	a, b, c = ...
	print("calling foo:", ...)
	return ...
end
print(foo(3, 4, 5))

function fwrite(fmt, ...)
	fmt = fmt or ""
	return io.write(string.format(fmt, ...))
end
fwrite()
fwrite("a\n")
fwrite("%d%d\n", 4, 5)

function list_v51(...)
	local num = select('#', ...)
	print("num ", num)
	for i=1, num do
		local arg = select(i, ...)
		print(arg)
	end
end
list_v51("a", "b", nil, "c", "d")

function list_v5(...)
	local arg = {...}; arg.n = select("#", ...)
	print("num ", arg.n)
	for i,v in ipairs(arg) do		--> will exit with nil
		print(v)
	end
end
list_v5("a", "b", nil, "c", "d")
