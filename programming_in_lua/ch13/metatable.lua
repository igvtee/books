t = {}
print(getmetatable(t))			--> nil

t1 = {}
setmetatable(t, t1)
assert(getmetatable(t) == t1)
