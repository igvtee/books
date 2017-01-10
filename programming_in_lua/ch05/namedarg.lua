--[[
-- invalid code
rename(old="temp.lua", new="temp1.lua")
]]--
function rename(arg)
	return os.rename(arg.old, arg.new)
end
-- rename{old="temp.lua", new="temp1.lua"}

--[[
w = Window {
x=0, y=0, width=300, height=200,
title="Lua", background="blue",
border=true
}

function Window(options)
	-- check mandatory options
	if type(options.title) ~= "string" then
		error("no title")
	elseif type(options.width) ~= "number" then
		error("no width")
	elseif type(options.height) ~= "number" then
		error("no height")
	end

	-- everything else is optional
	_Window(options.title,
		options.x or 0,
		options.y or 0,
		options.width, options.height,
		options.background or "white",
		options.border
	)
end
]]--
