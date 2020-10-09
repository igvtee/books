local lines = {}

for line in io.lines() do
	lines[#lines + 1] = line
end

table.sort(lines)

for _, l in ipairs(lines) do
	io.write(l, "\n")
end
