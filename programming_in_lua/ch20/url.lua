function unescape (s)
	s = string.gsub(s, "+", " ")
	s = string.gsub(s, "%%(%x%x)", function (h)
		return string.char(tonumber(h, 16))
	end)
	return s
end
print(unescape("a%2Bb+%3D+c")) --> a+b = c

cgi = {}
function decode (s)
	for name, value in string.gfind(s, "([^&=]+)=([^&=]+)") do
		name = unescape(name)
		value = unescape(value)
		cgi[name] = value
	end
end
function escape (s)
	s = string.gsub(s, "([&=+%c])", function (c)
		return string.format("%%%02X", string.byte(c))
	end)
	s = string.gsub(s, " ", "+")
	return s
end
function encode (t)
	local s = ""
	for k,v in pairs(t) do
		s = s .. "&" .. escape(k) .. "=" .. escape(v)
	end
	return string.sub(s, 2) -- remove first `&'
end
t = {name = "al", query = "a+b = c", q="yes or no"}
print(encode(t)) --> q=yes+or+no&query=a%2Bb+%3D+c&name=al
