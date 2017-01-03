x, y = 3, 4
a, b = 10, 2*x		-->	a=10, b=2*x
print(a, b)

x, y = y, x
print(x, y)

a, b, c = 0, 1
print(a, b, c)		--> 0	1	nil

a, b = a+1, b+1, b+2	--> value of b+2 is ignored
print(a, b)			--> 1	2

a, b, c = 0
print(a, b, c)		--> 0	nil	nil

a, b, c = 0, 0, 0
print(a, b, c)		--> 0	0	0

function f ()
	return 2, 3
end
a, b = f()
print(a, b)
