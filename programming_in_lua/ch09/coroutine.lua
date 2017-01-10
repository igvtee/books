co = coroutine.create(function () print("hi") end)
print(co)			--> thread: 0x8071d98
print(coroutine.status(co))			--> suspended
coroutine.resume(co)			--> hi
print(coroutine.status(co))			--> dead

co = coroutine.create(function (a, b, c)
	print("co", a, b, c)
end)
coroutine.resume(co, 1, 2, 3)			--> co	1	2	3

co = coroutine.create(function (a, b)
	coroutine.yield(a + b, a - b)
end)
print(coroutine.resume(co, 20, 10))			--> true	30	10

co = coroutine.create(function ()
	print("co", coroutine.yield())
end)
coroutine.resume(co)
coroutine.resume(co, 20, 10)			--> co	20	10

co = coroutine.create(function ()
	return 6, 7
end)
print(coroutine.resume(co))			--> true	6	7
