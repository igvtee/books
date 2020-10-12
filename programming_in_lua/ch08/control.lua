if a < 0 then a = 0 end
if a < b then return a else return b end
if line > MAXLINES then
	showpage()
	line = 0
end

if op == "+" then
	r = a + b
elseif op == "-" then
	r = a - b
elseif op == "*" then
	r = a * b
elseif op == "/" then
	r = a / b
else
	error("invalid operation")
end

local i = 1
while a[i] do
	print(a[i])
	i = i + 1
end


local line
repeat
	line = io.read()
until line ~= ""
print(line)

local sqr = x / 2
repeat
	sqr = (sqr + x/sqr) / 2
	local error = math.abs(sqr^2 - x)
until error < x/10000

for i = 1, math.huge do
	if (0.3*i^3 - 20*i^2 - 500 >= 0) then
		print(i)
		break
	end
end

for i = 1, 10 do print(i) end
max = i

local found = nil
fo i = 1, #a do
	if a[i] < 0 then
		found = 1
		break
	end
end
print(found)

function foo()
	return		--<< SYNTAX ERROR
	do return end	-- OK
end

while some_condition do
	::redo::
	if some_other_condition then goto continue
	elseif yet_another_condition then goto redo
	end
	::continue::
end
end
