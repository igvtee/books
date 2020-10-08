print(table.unpack({10, 20, 30}))
a, b = table.unpack{10, 20, 30}
print(a, b)

f = string.find
a = {"hello", "ll"}
print(f(table.unpack(a)))

print(table.unpack({"Sun", "Mon", "Tue", "Wed"}, 2, 3))

function unpack(t, i, n)
	i = i or 1
	n = n or #t
	if i <= n then
		return t[i], unpack(t, i+1, n)
	end
end
