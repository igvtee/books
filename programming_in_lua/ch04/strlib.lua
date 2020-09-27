print(string.len("abc"))
print(string.rep("abc", 3))
print(string.reverse("A Long Line!"))
print(string.lower("A Long Line!"))
print(string.upper("A Long Line!"))

s = "[in brackets]"
print(string.sub(s, 2, -2))
print(string.sub(s, 1, 1))
print(string.sub(s, -1, -1))

print(string.char(97))
i = 99; print(string.char(i, i+1, i+2))
print(string.byte("abc"))
print(string.byte("abc", 2))
print(string.byte("abc", -1))
print(string.byte("abc", 1, 2))

print(string.format("x = %d y = %d", 10, 20))
print(string.format("x = %x", 200))
print(string.format("x = 0x%X", 200))
print(string.format("x = %f", 200))
tag, title = "h1", "a title"
print(string.format("<%s>%s</%s>", tag, title, tag))

print(string.format("pi = %.4f", math.pi))
d = 5; m = 11; y = 1990
print(string.format("%02d/%02d/%04d", d, m, y))

print(string.find("hello world", "wor"))
print(string.find("hello world", "war"))

print(string.gsub("hello world", "l", "."))
print(string.gsub("hello world", "ll", ".."))
print(string.gsub("hello world", "a", "."))
