a = {"one", "two", "three"}
for i, v in ipairs(a) do
	print(i, v)
end

function iter (a, i)
	i = i + 1
	local v = a[i]
	if v then
		return i, v
	end
end
-- ipairs returns an iterator function, the table t, and 0
function ipairs (a)
	return iter, a, 0
end
for i, v in ipairs(a) do
	print(i, v)
end

-- pairs returns the next function, the table t, and nil
function pairs (t)
	return next, t, nil
end
for i, v in pairs(a) do
	print(i, v)
end

for i, v in next, a do
	print(i, v)
end

