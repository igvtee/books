while true do
	local block = io.read(2^13)
	if not block then break end
	io.write(block)
end

--[[
for block in io.input():lines(2^13) do
	io.write(block)
end
--]]
