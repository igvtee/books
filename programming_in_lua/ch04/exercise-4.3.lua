function insert(data, index, insert)
	return string.sub(data, 1, index-1) .. insert ..
		string.sub(data, index, -1)
end

print(insert("hello world", 1, "start: "))
print(insert("hello world", 7, "small "))
