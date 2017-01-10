names = {"Peter", "Paul", "Mary"}
grades = {Mary = 10, Paul = 7, Peter = 8}
function sortbygrade (names, grades)
	table.sort(names, function (n1, n2)
		return grades[n1] > grades[n2]		-->	compare the grades
	end)
end
sortbygrade(names, grades)
print(names[1], names[2], names[3])

function newCounter()
	local i = 0
	return function ()		--> anonymous function
			i = i + 1
			return i
		end
end
c1 = newCounter()
print(c1())		-->	1
print(c1())		--> 2
c2 = newCounter()
print(c2())		-->	1
print(c1())		--> 3
print(c2())		--> 2

--[[
function digitButton(digit)
	return Button{label=digit,
		action = function ()
			add_to_display(digit)
		end
	}
end
]]--

print(math.sin(60))
do
	local oldSin = math.sin
	local k = math.pi/180
	math.sin = function (x)
		return oldSin(x*k)
	end
end
print(math.sin(60))

do
	local oldOpen = io.open
	io.open = function (filename, mode)
		if access_OK(filename, mode) then
			return oldOpen(filename, mode)
		else
			return nil,	"access denied"
		end
	end
end
