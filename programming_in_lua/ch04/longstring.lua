page = [[
<html>
<head>
  <title>An HTML Page</title>
</head>
<body>
  <a href="http://www.lua.org">Lua</a>
</body>
</html>
]]

io.write(page)

page = [==[
a=b[c[i]]
]==]
io.write(page)

data = "\x00\x01\x02\x03\x04\x05\x06\x07\z
	\x08\x09\x0A\x0B\x0C\x0D\x0E\x0F"
io.write(data)
