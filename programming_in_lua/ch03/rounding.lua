print(math.floor(3.3))
print(math.floor(-3.3))
print(math.ceil(3.3))
print(math.ceil(-3.3))
print(math.modf(3.3))
print(math.modf(-3.3))
print(math.floor(2^70))

x = 2^52 + 1
print(string.format("%d %d", x, math.floor(x + 0.5)))

function round(x)
	local f = math.floor(x)
	if (x == f) or (x % 2.0 == 0.5) then
		return f
	else
		return math.floor(x + 0.5)
	end
end
print(round(2.5))
print(round(3.5))
print(round(-2.5))
print(round(-1.5))
