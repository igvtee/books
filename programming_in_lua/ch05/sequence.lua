a = {}
for i = 1, 4 do
	a[i] = io.read()
end

for i = 1, #a do
	print(a[i])
end

print(a[#a])
a[#a] = nil
a[#a + 1] = "v"
