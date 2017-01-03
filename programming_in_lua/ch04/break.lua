i = 1
v = 8
a = {2, 4, 6, 8, 10, 12}
while a[i] do
	print(a[i])
	if a[i] == v then
		break
	end
	i = i + 1
end

function foo ()
	print("foo begian")
	do
		return
	end
	print("foo end")
end

foo()
