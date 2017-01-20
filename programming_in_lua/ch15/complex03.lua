local P = {}
if _REQUIREDNAME == nil then
	complex = P
else
	_G[_REQUIREDNAME] = P
end
setmetatable(P, {__index = _G})
--[[
local _G = _G
]]--
setfenv(1, P)

local function checkComplex (c)
	if not ((type(c) == "table") and tonumber(c.r) and tonumber(c.i)) then
		error("bad complex number", 3)
	end
end

local function new (r, i) return {r=r, i=i} end

local function add (c1, c2)
	checkComplex(c1)
	checkComplex(c2)
	return P.new(c1.r + c2.r, c1.i + c2.i)
end

local function sub (c1, c2)
	checkComplex(c1)
	checkComplex(c2)
	return P.new(c1.r - c2.r, c1.i - c2.i)
end

local function mul (c1, c2)
	checkComplex(c1)
	checkComplex(c2)
	return P.new(c1.r*c2.r - c1.i*c2.i, c1.r*c2.i + c1.i*c2.r)
end

local function inv (c)
	checkComplex(c)
	local n = c.r^2 + c.i^2
	return  P.new(c.r/n, -c.i/n)
end

complex = {
	new = new,
	add = add,
	sub = sub,
	mul = mul,
	div = div,
}

return complex
