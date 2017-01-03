days = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}
print(days[4])	-->	"Wednesday"

a = {x=0, y=0}	--> a = {}; a.x=0; a.y=0

w = {x=0, y=1, label="console"}
x = {math.sin(0), math.sin(1), math.sin(2)}
print(w[1])		--> nil
w[1] = "another field"
x.f = w
print(w["x"])	-->	0
print(w[1])		--> another field
print(x.f[1])	-->	another field
print(x[2])		-->	sin(1)
w.x = nil		--> remote field x

polyline = {color="blue", thickness=2, nponts=4,
{x=0, y=0},
{x=-10, y=0},
{x=-10, y=1},
{x=0, y=1}
}
print(polyline[2].x)	--> -10

opnames = {["+"] = "add", ["-"] = "sub", ["*"] = "mul", ["/"] = "div"}
i = 20; s = "-"
a = {[i+0] = s, [i+1] = s..s, [i+2] = s..s..s}
print(opnames[s])	--> sub
print(a[22])		--> ---

--[[
{x=0, y=0}	<-->	{["x"]=0, ["y"]=0}
{"red", "green", "blue"}	<-->	{[1]="red", [2]="green", [3]="blue"}
days = {[0]="Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}
a = {[1]="red", [2]="green", [3]="blue",}
{x=10, y=45; "one", "two", "three"}
]]--
