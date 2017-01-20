a = {10, 20, 30}
for k,v in pairs(a) do print(v) end
table.insert(a, 1, 15)
for k,v in pairs(a) do print(v) end
table.insert(a, 40)
for k,v in pairs(a) do print(v) end
table.remove(a)
table.remove(a, 1)
for k,v in pairs(a) do print(v) end
