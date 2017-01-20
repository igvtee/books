data = "This is a string"
print(string.len(data))
print(string.rep(data, 2))
print(string.lower(data))
print(string.upper(data))
print(string.sub(data, 6, 7))
-- string.sub(data, 1)
print(string.sub(data, 1, -1))
print(string.sub(data, 1, -7))

print(string.char(97))					--> a
i = 99; print(string.char(i, i+1, i+2))	--> cde
print(string.byte("abc"))				--> 97
print(string.byte("abc", 2))			--> 98
print(string.byte("abc", -1))			--> 99

print(string.format("pi = %.4f", math.pi))	--> pi = 3.1416
d = 5; m = 11; y = 1990
print(string.format("%02d/%02d/%04d", d, m, y))	--> 05/11/1990
tag, title = "h1", "a title"
print(string.format("<%s>%s</%s>", tag, title, tag))	--> <h1>a title</h1>
