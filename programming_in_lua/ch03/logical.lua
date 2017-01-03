print(4 and 5)		--> 5
print(nil and 13)	--> nil
print(false and 13)	--> false
print(4 or 5)		--> 4
print(false or 5)	--> 5

-- if x is false or nil init it to v
v = 10
x = x or v
print(x)
x = false
if not x then
	x = v
end
print(x)

-- C language a ? b : c == (a and b) or c

print(not nil)		--> true
print(not false)	--> true
print(not 0)		--> false
print(not not nil)	--> false
