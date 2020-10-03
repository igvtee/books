a = {}
k = "x"
a[k] = 10
a[20] = "great"
print(a["x"])
k = 20
print(a[k])
a["x"] = a["x"]+1
print(a["x"])

a = {}
a["x"] = 10
b = a
print(b["x"])
b["x"] = 20
print(a["x"])
a = nil
b = nil
