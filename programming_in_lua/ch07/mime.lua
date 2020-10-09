t = io.read("*a")
t = string.gsub(t, "([\128-\255=])",
	function(c)
		return string.format("=%02X", string.byte(c))
	end)
io.write(t)
