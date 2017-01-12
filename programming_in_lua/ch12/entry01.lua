local count = 0
local data = "data01.lua"

function Entry (b) count = count+1 end
dofile(data)
print("number of entries: " .. count)

local authors = {} -- a set to collect authors
function Entry (b) authors[b[1]] = true end
dofile(data)
for name in pairs(authors) do print(name) end
