function remove(data, index, length)
	return string.sub(data, 1, index-1) .. string.sub(data, index+length, -1)
end

print(remove("hello world", 7, 4))
