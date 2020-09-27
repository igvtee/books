function _ispali(data)
	len = math.floor(#data / 2)
	s1 = string.sub(data, 1, len)
	s2 = string.sub(data, #data-len+1, -1)
	s2 = string.reverse(s2)
	return s1 == s2
end

function ispali(data)
	new = string.gsub(data, " ", "")
	new = string.gsub(new, ",", "")
	return _ispali(new)
end

print(ispali("step on no pets"))
print(ispali("banana"))
