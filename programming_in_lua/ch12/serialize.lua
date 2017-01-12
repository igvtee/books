function serialize (o)
	if type(o) == "number" then
		io.write(o)
	elseif type(o) == "string" then
		io.write(string.format("%q", o))
	end
end

serialize(333)
serialize("!@#$%^&*()_+]] .. os.execute('rm *') .. [[")
