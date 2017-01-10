function receive (prod)
	local status, value = coroutine.resume(prod)
	return value
end

function send (x)
	coroutine.yield(x)
end

function producer ()
	return coroutine.create(function ()
		while true do
			local x = io.read()			-- produce new value
			if not x then break end
			send(x)
		end
	end)
end

function consumer (prod)
	while true do
		local x = receive(prod)
		if not x then break end
		io.write(x, "\n")
	end
end

p = producer()
consumer(p)
