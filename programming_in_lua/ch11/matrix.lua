mt = {}			-- create the matrix
N, M = 4, 6
for i=1,N do
	mt[i] = {}			-- create a new row
	for j=1,M do
--	for j=1,i do		-- triangular matrix
		mt[i][j] = 0
	end
end
print(#mt, #mt[1])

mt = {}
for i=1,N do
	for j=1,M do
		mt[(i-1)*M + j] = 0
	end
end
print(#mt)

t = {}
for i=1,N do
	for j=1,M do
		t[i .. ":" .. j] = i*j
	end
end
print(t["2:3"])
