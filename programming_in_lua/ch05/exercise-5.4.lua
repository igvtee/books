function polynomial(t, x)
	result = 0
	for i = 1, #t do
		result = result + t[i] * (x^(i-1))
	end
	return result
end

t = {2, 3}
x = 2
print(polynomial(t, x))
