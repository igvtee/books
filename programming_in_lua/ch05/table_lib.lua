t = {10, 20, 30}
table.insert(t, 1, 15)
table.insert(t, 40)
print(#t)
table.remove(t, 1)
table.remove(t)
print(#t)
-- table.move(a, f, e, t)
-- table.move(a, 1, #a, 1, {})
-- table.move(a, 1, #a, #b + 1, b)

t = {}
for line in io.lines() do
	table.insert(t, line)
end
print(#t)
