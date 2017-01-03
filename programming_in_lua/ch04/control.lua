--[[
if conditions then
	then-part
end

if conditions then
	then-part
else
	else-part
end

if conditions then
	then-part
elseif conditions then
	else-part
...
else
	else-part
end

while condition do
	statements;
end

repeat
	statements;
until condition

for var=exp1, exp2, exp3 do
	loop-part
end



]]--

for i=10,1,-2 do	-- i is locale of for
	print(i)
end
for i=1,10,4 do
	print(i)
	--i = 11			-- can not change i. the behavior is undefine
	if i==5 then
		break
	end
end

days = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}
revdays = {}
for i,v in ipairs(days) do
	revdays[v] = i
end
x = "Tuesday"
print(revdays[x])	-->	3
for k in pairs(revdays) do
	print(k)
end
