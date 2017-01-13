-- create a namespace
Window = {}

-- create the prototype with default values
Window.prototype = {x=0, y=0, width=100, height=100,}

-- create a metatable
Window.mt = {}

-- declare the constructor function
function Window.new (o)
	setmetatable(o, Window.mt)
	return o
end

-- version 1
Window.mt.__index = function (table, key)
	print(key)
	return Window.prototype[key]
end

w = Window.new{x=10, y=20}
print(w.width)			--> 100
print(w.x)				--> 10


-- version 2
Window.mt.__index = Window.prototype
w = Window.new{x=10, y=20}
print(w.width)			--> 100

-- without invoking __index metamethod
print(rawget(w, "width"))			--> nil
print(rawget(w, "x"))			--> 10
rawset(w, "bgclolr", "black")
print(w.bgclolr)				--> black
