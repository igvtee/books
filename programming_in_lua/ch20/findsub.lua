s = "hello world"
i, j = string.find(s, "hello")
print(i, j)						--> 1 5
print(string.sub(s, i, j))		--> hello
print(string.find(s, "world"))	--> 7 11
i, j = string.find(s, "l")
print(i, j)						--> 3 3
print(string.find(s, "lll"))	--> nil

s = "hello world hello"
i, j = string.find(s, "hello", 6)
print(i, j)						--> 13 17

s = string.gsub("Lua is cute", "cute", "great")
print(s) --> Lua is great
s = string.gsub("all lii", "l", "x")
print(s) --> axx xii
s = string.gsub("Lua is great", "perl", "tcl")
print(s) --> Lua is great
s = string.gsub("all lii", "l", "x", 1)
print(s) --> axl lii
s, count = string.gsub("all lii", "l", "x", 2)
print(s, count) --> axx lii
