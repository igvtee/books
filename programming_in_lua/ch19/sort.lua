-- version 1
lines = {
	luaH_set = 10,
	luaH_get = 24,
	luaH_present = 48,
}

a = {}
for n in pairs(lines) do a[#a + 1] = n end
table.sort(a)
for i,n in ipairs(a) do print(n) end

-- version 2
function pairsByKeys (t, f)
	local a = {}
	for n in pairs(t) do a[#a + 1] = n end
	table.sort(a, f)
	local i = 0 -- iterator variable
	return function () -- iterator function
		i = i + 1
		return a[i], t[a[i]]
	end
end

for name, line in pairsByKeys(lines) do
	print(name, line)
end
