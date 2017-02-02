--[[
"call" events happen every time Lua calls a function
"return" events happen every time a function returns
"line" events happen when Lua starts executing a new line of code
"count" events happen after a given number of instructions

To register a hook, we call debug.sethook with two or three arguments:
the first argument is the hook function; the second argument is a string that
describes the events we want to monitor; and an optional third argument is
a number that describes at what frequency we want to get count events

debug.sethook(<function>, <type>, <count>)
type: "c", "r", "l" (call, return, line)
]]--

-- debug.sethook(print, "l")

function trace (event, line)
	local s = debug.getinfo(2).short_src
	print(s .. ":" .. line)
end
debug.sethook(trace, "l")

print("hello world")
