local data = "data02.lua"

local authors = {} -- a set to collect authors
function Entry (b)
	if b.author then
		authors[b.author] = true
	end
end
dofile(data)
for name in pairs(authors) do print(name) end
