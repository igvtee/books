print(10 .. 20)
print("10" + 1)

print(tonumber("  -3 "))
print(tonumber(" 10e4 "))
print(tonumber("10e"))
print(tonumber("0x1.3p-4"))

print(tonumber("100101", 2))
print(tonumber("fff", 16))
print(tonumber("-ZZ", 36))
print(tonumber("987", 8))

print(tostring(10) == "10")
