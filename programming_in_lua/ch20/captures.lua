pair = "name = Anna"
key, value = string.match(pair, "(%a+)%s*=%s*(%a+)")
print(key, value) --> name Anna

date = "Today is 17/7/1990"
d, m, y = string.match(date, "(%d+)/(%d+)/(%d+)")
print(d, m, y) --> 17 7 1990

s = [[then he said: "it's all right"!]]
-- "[\"'].-[\"']" not work
q, quotedPart = string.match(s, "([\"'])(.-)%1")
print(quotedPart) --> it's all right
print(q) --> "

print(string.gsub("hello Lua!", "(%a)", "%1-%1")) --> h-he-el-ll-lo-o L-Lu-ua-a!
print(string.gsub("hello Lua", "(.)(.)", "%2%1")) --> ehll ouLa

data = "the \\quote{task} is to \\em{change} that."
print(data)
print(string.gsub(data, "\\(%a-){(.-)}", "<%1>%2</%1>"))

function trim (s)
	return (string.gsub(s, "^%s*(.-)%s*$", "%1"))
end

function expand (s)
	s = string.gsub(s, "$(%w+)", function (n)
		return _G[n]
	end)
	return s
end
name = "Lua"; status = "great"
print(expand("$name is $status, isn't it?")) --> Lua is great, isn't it?

function expand (s)
	return (string.gsub(s, "$(%w+)", function (n)
		return tostring(_G[n])
	end))
end
print(expand("print = $print; a = $a")) --> print = function: 0x8050ce0; a = nil

s = "sin(3) = $[math.sin(3)]; 2^5 = $[2^5]"
print((string.gsub(s, "$(%b[])", function (x)
	x = "return " .. string.sub(x, 2, -2)
	local f = loadstring(x)
	return f()
end))) --> sin(3) = 0.1411200080598672; 2^5 = 32
