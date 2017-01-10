a = {p = print}
a.p("Hello World")
print = math.sin
a.p(print(1))		-->	0.841470
sin = a.p
sin(10, 20)			--> 10	20
print = a.p
--[[
function foo (x) return 2*x end
foo = function (x) return 2*x end
]]--

network = {
	{name="grauna",	ip="210.26.30.34"},
	{name="arraial",	ip="210.26.30.23"},
	{name="lua",	ip="210.26.23.12"},
	{name="derain",	ip="210.26.23.20"},
}
table.sort(network, function (a, b)
		return (a.name > b.name)
	end)
print(network[1].name, network[2].name, network[3].name, network[4].name)

function derivative(f, delta)
	delta = delta or 1e-4
	return function (x)
			return (f(x + delta) - f(x))/delta
		end
end
c = derivative(math.sin)
print(math.cos(10), c(10))
