--[[
require
	1. search and load module
	2. prevent load same module again
]]--
require "foo"
for i, v in pairs(package.loaded) do
	print(i, v);
end
