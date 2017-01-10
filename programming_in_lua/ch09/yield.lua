co = coroutine.create(function ()
	for i=1,5 do
		print("co", i)
		coroutine.yield()
	end
end)
coroutine.resume(co)			--> co	1
print(coroutine.status(co))			--> suspended
coroutine.resume(co)			--> co	2
coroutine.resume(co)			--> co	3
coroutine.resume(co)			--> co	4
coroutine.resume(co)			--> co	5
print(coroutine.status(co))			--> suspended
coroutine.resume(co)			--> prints nothing
print(coroutine.status(co))			--> dead
print(coroutine.resume(co))			--> false   cannot resume dead coroutine
