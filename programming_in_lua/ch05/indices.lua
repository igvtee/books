a = {}
for i = 1, 1000 do a[i] = i*2 end
print(a[9])
a["x"] = 10
print(a["x"])
print(a["y"])

a = {}
a.x = 10
print(a.x)
print(a.y)

a = {}
x = "y"
a[x] = 10
print(a[x])
print(a.x)
print(a.y)

i = 10; j = "10"; k = "+10"
a = {}
a[i] = "number key"
a[j] = "string key"
a[k] = "another string key"
print(a[i])
print(a[j])
print(a[k])
print(tonumber(j))
print(tonumber(k))

a = {}
a[2.0] = 10
a[2.1] = 20
print(a[2])
print(a[2.1])
