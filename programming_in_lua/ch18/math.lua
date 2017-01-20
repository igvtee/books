print(math.random())			-- [0,1)
print(math.random(10))			-- 1 <= x <= 10
print(math.random(10, 20))		-- 10 <= x <= 20

math.randomseed(os.time())
print(math.random())			-- [0,1)
