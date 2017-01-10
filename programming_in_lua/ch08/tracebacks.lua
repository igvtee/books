print(debug.traceback())

function foo (str)
	if type(str) ~= "string" then
		error("string expected", 2)
	end
end
foo({x=1})
