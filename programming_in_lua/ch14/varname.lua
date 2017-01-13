day = "Sunday"
varname = "day"

-- version 1
--loadstring("value = " .. varname)()
value = loadstring("return " .. varname)()
print(value)

-- version 2
value = _G[varname]
print(value)

-- version 3
-- _G["io.read"] => getfield("io.read")
function getfield (f)
	local v = _G			-- start with the table of globals
	for w in string.gfind(f, "[%w_]+") do
		v = v[w]
	end
	return v
end
mywrite = getfield("io.write")
mywrite("io.write\n")

function setfield (f, v)
	local t = _G			-- start with the table of globals
	for w, d in string.gfind(f, "([%w_]+)(.?)") do
		if d == "." then			-- not last field?
			t[w] = t[w] or {}			-- create table if absent
			t = t[w]			-- get the table
		else			-- 	last field
			t[w] = v			-- do the assignment
		end
	end
end
setfield("t.x.y", 10)
print(t.x.y)			--> 10
print(getfield("t.x.y"))			--> 10
