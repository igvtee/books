-- version 1
function setDefault (t, d)
	local mt = {__index = function () return d end}
	setmetatable(t, mt)
end

tab = {x=10, y=20}
print(tab.x, tab.z)			--> 10	nil
setDefault(tab, 0)
print(tab.x, tab.z)			--> 10	0

-- version 2
local mt = {__index = function () return t.___ end}
function SetDefault (t, d)
	t.___ = d
	setmetatable(t, mt)
end
setDefault(tab, 1)
print(tab.x, tab.z)			--> 10	1

-- version 3
local key = {}			-- unique key
local mt = {__index = function (t) return t[key] end}
function setDefault (t, d)
	t[key] = d
	setmetatable(t, mt)
end
setDefault(tab, 2)
print(tab.x, tab.z)			--> 10	2
