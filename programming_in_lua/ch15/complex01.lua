local P = {}
complex = P			-- package name

local function checkComplex (c)
	if not ((type(c) == "table") and tonumber(c.r) and tonumber(c.i)) then
		error("bad complex number", 3)
	end
end

function P.new (r, i) return {r=r, i=i} end

function P.add (c1, c2)
	checkComplex(c1)
	checkComplex(c2)
	return P.new(c1.r + c2.r, c1.i + c2.i)
end

function P.sub (c1, c2)
	checkComplex(c1)
	checkComplex(c2)
	return P.new(c1.r - c2.r, c1.i - c2.i)
end

function P.mul (c1, c2)
	checkComplex(c1)
	checkComplex(c2)
	return P.new(c1.r*c2.r - c1.i*c2.i, c1.r*c2.i + c1.i*c2.r)
end

function P.inv (c)
	checkComplex(c)
	local n = c.r^2 + c.i^2
	return  P.new(c.r/n, -c.i/n)
end

return complex
