local socket = require "socket"

function receive (connection)
	connection:settimeout(0)			-- do not block
	local s, status, partial = connection:receive(2^10)
	if status == "timeout" then
		coroutine.yield(connection)
	end
	return s or partial, status
end

function download (host, file)
--	local c = assert(socket.connect(host, 80))
	local c, msg = socket.connect(host, 80)
	if not c then error(msg) end
	local count = 0			-- counts number of bytes read
	c:send("GET " .. file .. " HTTP/1.0\r\n\r\n")
	while true do
		local s, status = receive(c)
		count = count + #s
		if status == "closed" then break end
	end

	c:close()
	print(file, count)
end

threads = {}			-- list of all live threads
function get (host, file)
	-- create coroutine
	local co = coroutine.create(function ()
		download(host, file)
	end)
	-- insert it in the list
	table.insert(threads, co)
end

function dispatch ()
	local i = 1
	while true do
		if threads[i] == nil then			-- no more threads?
			if threads[1] == nil then break end			-- list is empty?
			i = 1			-- restart the loop
		end
		local status = coroutine.resume(threads[i])
		if not status then			-- thread finished it's task?
			table.remove(threads, i)
		else
			i = i + 1
		end
	end
end

host = "www.w3.org"

get(host, "/TR/html401/html40.txt")
get(host, "/TR/2002/REC-xhtml1-20020801/xhtml1.pdf")
get(host, "/TR/REC-html32.html")
get(host, "/TR/2000/REC-DOM-Level-2-Core-20001113/DOM2-Core.txt")

dispatch() -- main loop
