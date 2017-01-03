a = "one string"
b = string.gsub(a, "one", "another")
print(a)
print(b)

print("one line\nnext line\n\"in quotes\", 'in quotes'")
print('a blackslash inside quotes: \'\\\'')
print("a simpler way: '\\'")

print("alo\n123\"")
print('\97lo\10\04923"')

page = [[
<HTML>
<HEAD>
<TITLE>An HTML Page</TITLE>
</HEAD>
<BODY>
Lua
[a text between double brackets]
</BODY>
</HTML>
]]
io.write(page)

-- auto convert string and number
print("10" + 1)
print("10 + 1")
print("-5.3e-10" * "2")
-- print("hello" + 1)
print(10 .. 20)

-- but number and string are not equal
if 10 == "10" then
	print("equal 10")
else
	print("not equal 10")
end
print(tostring(10) == "10")		--> true
print(10 .. "" == "10")			--> true
