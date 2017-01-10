function permgen (a, n)
	if n == 0 then
		coroutine.yield(a)
	else
		for i=1,n do
			-- put i-th element as the last one
			a[n], a[i] = a[i], a[n]

			-- generate all permutations of the other elements
			permgen(a, n-1)

			-- restore i-th element
			a[n], a[i] = a[i], a[n]
		end
	end
end

function perm (a)
	local n = table.getn(a)
	local co = coroutine.create(function () permgen(a, n) end)
	return function ()			-- iterator
		local code, res = coroutine.resume(co)
		return res
	end
end

function printResult (a)
	for i,v in ipairs(a) do
		io.write(v, " ")
	end
	io.write("\n")
end

for p in perm{"a", "b", "c"}  do
	printResult(p)
end
