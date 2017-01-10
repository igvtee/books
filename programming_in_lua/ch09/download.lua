local socket = require "socket"

function download (host, file)
	local c = assert(socket.connect(host, 80))
	local count = 0			-- counts number of bytes read
	c:send("GET " .. file .. " HTTP/1.0\r\n\r\n")
	while true do
		local s, status, partial = c:receive(2^10)
--		io.write(s or partial)
		count = count + #(s or partial)
		if status == "closed" then break end
	end

	c:close()
	print(file, count)
end

host = "www.w3.org"

download(host, "/TR/html401/html40.txt")
download(host, "/TR/2002/REC-xhtml1-20020801/xhtml1.pdf")
download(host, "/TR/REC-html32.html")
download(host, "/TR/2000/REC-DOM-Level-2-Core-20001113/DOM2-Core.txt")
