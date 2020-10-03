function isarray(t)
	i = 1
	for _ in pairs(t) do
		if t[i] == nil then
			return false
		end
		i = i+1
	end
	return true
end

print(isarray({10, 20, 30}))
print(isarray({[1]=10, [3]=20, [4]=30}))
print(isarray({aa=10, bb=20, cc=30}))
