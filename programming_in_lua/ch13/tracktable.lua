-- version 1
-- original table (created somewhere)
t = {}
-- keep a private access to original table
local _t = t
-- create proxy
t = {}
-- create metatable
local mt = {
	__index = function (t, k)
		print("*access to element " .. tostring(k))
		return _t[k]			-- access the original table
	end,
	__newindex = function (t, k, v)
		print("*update of element " .. tostring(k) .. " to " .. tostring(v))
		_t[k] = v			-- update original table
	end,
}
setmetatable(t, mt)
t[2] = "hello"
print(t[2])

-- version 2
-- create private index
local index = {}
-- create metatable
local mt = {
	__index = function (t, k)
		print("*access to element " .. tostring(k))
		return t[index][k]			-- access the original table
	end,
	__newindex = function (t, k, v)
		print("*update of element " .. tostring(k) .. " to " .. tostring(v))
		t[index][k] = v			-- update original table
	end,
}
function track (t)
	local proxy = {}
	proxy[index] = t
	setmetatable(proxy, mt)
	return proxy
end
t = {}
t = track(t)
t[2] = "hello"
print(t[2])
