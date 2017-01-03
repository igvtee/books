a = {}; a.x = 1; a.y = 0
b = {}; b.x = 1; b.y = 0
c = a
if a ~= b then
	print("a ~= b")
end
if a == c then
	print("a == c")
end

if "0" ~= 0 then
	print('"0" ~= 0')
end
if 2 < 15 then
	print("2 < 15")
end
if "2" < "15" then
	print('"2" < "15"')
end
--[[
if 2 < "15" then
	print('2 < "15"')
end
]]--
