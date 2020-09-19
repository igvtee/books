print(type(nil))
print(type(true))
print(type(10.4 * 3))
print(type("Hello world"))
print(type(io.stdin))
print(type(print))
print(type(type))
print(type({}))
print(type(type(X)))

co = coroutine.create(function () print("hi") end)
print(type(co))

print(type(a))
a = 10
print(type(a))
a = "a string!!"
print(type(a))
a = nil
print(type(a))
