MAX_POLY = 2

function polynomial(t, x)
	result = 0
	for i = 1, #t do
		result = result + t[i] * (x^(i-1))
		if i == MAX_POLY then
			return result
		end
	end
	return result
end

t = {2, 3, 4, 5}
x = 2
print(polynomial(t, x))
