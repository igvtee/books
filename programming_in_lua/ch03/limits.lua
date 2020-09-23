--[[
print(math.maxinteger + 1)
print(math.mininteger - 1)
print(-math.mininteger == math.maxinteger)
print(math.mininteger // -1)
--]]

print(12.7 - 20 + 7.3)

--[[
print(math.maxinteger + 2)
print(math.maxinteger + 2.0)
print(math.maxinteger + 2.0 == math.maxinteger + 1.0)
--]]

-- integer [-2^53, 2^53] 9007199254740992 

print(-3 + 0.0)
print(0x7fffffffffffffff + 0.0)

print(9007199254740991 + 0.0 == 9007199254740991)
print(9007199254740992 + 0.0 == 9007199254740992)
print(9007199254740993 + 0.0 == 9007199254740993)
print(string.format("%d", 9007199254740991 + 0.0))
print(string.format("%d", 9007199254740992 + 0.0))
print(string.format("%d", 9007199254740993 + 0.0))
print(string.format("%d", 9007199254740993))

--[[
print(2^53)
print(2^53 | 0)
print(3.2 | 0)
print(2^64 | 0)
--]]
print(math.random(1, 3.5))

--[[
print(math.tointeger(-258.0))
print(math.tointeger(2^30))
print(math.tointeger(5.01))
print(math.tointeger(2^64))
--]]
