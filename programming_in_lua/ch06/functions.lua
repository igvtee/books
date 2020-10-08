print "Hello World"
-- dofile 'a.lua'
print [[a multi-line
 message]]
--f{x=10, y=20}
print(type{})

function f(a, b)
	print(a, b)
end
f()
f(3)
f(3, 4)
f(3, 4, 5)

globalCounter=0
function incCount(n)
	n = n or 1
	globalCounter = globalCounter + n
end
incCount()
print(globalCounter)
