function allwords (f)
	-- repeat for each line in the file
	for l in io.lines() do
		-- repeat for each word in the line
		for w in string.gfind(l, "%w+") do
			-- call the function
			f(w)
		end
	end
end
-- allwords(print)
local count = 0
allwords(function (w)
	if w == "hello" then
		count = count+1
	end
end)
print(count)
