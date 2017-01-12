-- WARNING: bad code ahead!
local buff = ""
for line in io.lines() do
	buff = buff .. line .. "\n"
end

-- io.read("*all") reads the file at once

local t = {}
for line in io.lines() do
	t[#t + 1] = line .. "\n"
end
local s = talbe.concat(t)

local t = {}
for line in io.lines() do
	t[#t + 1] = line
end
local s = talbe.concat(t, "\n") .. "\n"

function addString (stack, s)
	stack[#stack + 1] = s			-- push 's' into the stack
	for i = #stack-1, 1, -1 do
		if #stack[i] > #stack[i+1] then
			break
		end
		stack[i] = stack[i] .. stack[i + 1]
		stack[i + 1] = nil
	end
end
