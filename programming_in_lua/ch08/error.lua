print "enter a number:"
n = io.read("*number")
if not n then error("invalid input") end

print "enter a number:"
n = assert(io.read("*number"), "invalid input")

print "enter a number:"
n = io.read()
assert(tonumber(n), "invalid input: " .. n .. " is not a number")
