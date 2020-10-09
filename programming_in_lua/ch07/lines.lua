local count = 0
for line in io.lines() do
	count = count + 1
	io.write(string.format("%6d ", count), line, "\n")
end
