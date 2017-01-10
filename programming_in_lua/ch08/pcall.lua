-- pcall : protected call
function foo ()
	a = 444
	print(a[0])
--	print(a)
	print("end")
end
status, err = pcall(foo)
if status then
	print "no error"
else
	print("error " .. err)
end

local status, err = pcall(function() error({code=121}) end)
print(err.code)			--> 121
