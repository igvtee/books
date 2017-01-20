test = [[char s[] = "a /* here"; /* a tricky string */]]
print(string.gsub(test, "/%*.-%*/", "<COMMENT>")) --> char s[] = "a <COMMENT>

i, j = string.find(";$% **#$hello13", "%a*")
print(i,j) --> 1 0

pattern = string.rep("[^\n]", 70) .. "[^\n]*"

function nocase (s)
	s = string.gsub(s, "%a", function (c)
		return string.format("[%s%s]", string.lower(c),
		string.upper(c))
	end)
	return s
end
print(nocase("Hi there!")) --> [hH][iI] [tT][hH][eE][rR][eE]!

--[[
s1 = string.gsub(s1, "(%W)", "%%%1")
s2 = string.gsub(s2, "%%", "%%%%")
]]--

function code (s)
	return (string.gsub(s, "\\(.)", function (x)
		return string.format("\\%03d", string.byte(x))
	end))
end

function decode (s)
	return (string.gsub(s, "\\(%d%d%d)", function (d)
		return "\\" .. string.char(tonumber(d))
	end))
end

s = [[follows a typical string: "This is "great"!".]]
s = code(s)
s = string.gsub(s, '(".-")', string.upper)
s = decode(s)
print(s) --> follows a typical string: "THIS IS "GREAT"!".

-- 
function code (s)
	return (string.gsub(s, '\\(%A)', function (x)
		return string.format("\\%03d", string.byte(x))
	end))
end

function decode (s)
	return (string.gsub(s, '\\(%d%d%d)', string.char))
end
s = [[a \emph{command} is written as \\command\{text\}.]]
s = code(s)
s = string.gsub(s, "\\(%a+){(.-)}", "<%1>%2</%1>")
print(decode(s)) --> a <emph>command</emph> is written as \command{text}.
