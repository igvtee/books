s = "hello hi, again!"
words = {}
string.gsub(s, "(%a+)", function (w)
	table.insert(words, w)
end)
print(table.concat(words, " "))

words = {}
for w in string.gfind(s, "%a+") do
	table.insert(words, w)
end
print(table.concat(words, " "))
