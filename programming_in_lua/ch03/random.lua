-- [0,1)
print(math.random())

-- [1,4)
print(math.random(4))

-- [2,5]
print(math.random(2, 5))

math.randomseed(os.time())
print(math.random())
