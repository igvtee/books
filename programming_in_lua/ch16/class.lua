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

a = Account:new{balance = 0}
-- getmetatable(a).__index.deposit(a, 100.00)
-- Account.deposit(a, 100.00)
a:deposit(100.00)

b = Account:new()
print(b.balance)			--> 0
b:deposit(100.00)
print(b.balance)			--> 100
print(Account.balance)			--> 0
