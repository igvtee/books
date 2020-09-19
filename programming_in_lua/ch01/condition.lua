cond = nil
if cond then
	print("cond(nil) is true")
else
	print("cond(nil) is false")
end

cond = false
if cond then
	print("cond(false) is true")
else
	print("cond(false) is false")
end

cond = 0
if cond then
	print("cond(0) is true")
else
	print("cond(0) is false")
end

cond = ""
if cond then
	print("cond(\"\") is true")
else
	print("cond(\"\") is false")
end
