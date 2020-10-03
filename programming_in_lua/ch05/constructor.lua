days = {"Sunday", "Monday", "Tuesday", "Wednesday",
	"Thursday", "Friday", "Saturday"}
print(days[4])

a = {x = 10, y = 20}
a = {}; a.x = 10; a.y = 20

w = {x = 0, y= 0, label = "console"}
x = {math.sin(0), math.sin(1), math.sin(2)}
w[1] = "another field"
x.f = w
print(w["x"])
print(w[1])
print(x.f[1])
w.x = nil

polyline = {color="blue",
	thickness=2,
	npoints=4,
	{x=0, y=0},	-- polyline[1]
	{x=-10, y=0},	-- polyline[2]
	{x=-10, y=1},	-- polyline[3]
	{x=0, y=1},	-- polyline[4]
	}
print(polyline[2].x)
print(polyline[4].y)

opnames = {["+"] = "add", ["-"] = "sub",
	["*"] = "mul", ["/"] = "div"}
i = 20; s = "-"
a = {[i+0] = s, [i+1] = s..s, [i+2] = s..s..s}
print(opnames[s])
print(a[22])

-- {["x"] = 0, ["y"] = 0}
a = {x = 0, y = 0}
-- {[1] = "r", [2] = "g", [3] = "b"}
a = {"r", "g", "b"}
a = {[1] = "red", [2] = "green", [3] = "blue",}
