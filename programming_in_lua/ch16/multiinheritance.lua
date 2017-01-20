-- look up for 'k' in list of tables 'plist'
local function search (k, plist)
	for i=1, #plist do
		local v = plist[i][k]			-- try 'i'-th superclass
		if v then
			return v
		end
	end
end

function createClass (...)
	local c = {}			-- new class
	local parents = {...}

	-- class will search for each method in the list of its parents
	setmetatable(c, {__index = function (t, k)
		return search(k, parents)
	end})
--[[
	setmetatable(c, {__index = function (t, k)
		local v = search(k, arg)
		t[k] = v			-- save for next access
		return v
	end})
]]--
	-- prepare 'c' to be the metatable of its instances
	c.__index = c
	-- define a new constructor for this new class
	function c:new (o)
		o = o or {}
		setmetatable(o, c)
		return o
	end
	return c			-- return new class
end

Named = {}
function Named:getname ()
	return self.name
end

function Named:setname (n)
	self.name = n
end

Account = {balance = 0}
function Account:new (o)
	o = o or {}			-- create object if user does not provide one
	-- make self a prototype for o
	setmetatable(o, self)
	self.__index = self
	return o
end

function Account:deposit (v)
	self.balance = self.balance + v
end

NamedAccount = createClass(Account, Named)
account = NamedAccount:new{name = "Paul"}
print(account:getname())			--> Paul
