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

function Account:withdraw (v)
	if v > self.balance then
		error("insufficient funds", 2)
	end
	self.balance = self.balance - v
end

SpecialAccount = Account:new()
function SpecialAccount:withdraw (v)
	if v - self.balance >= self:getLimit() then
		error("insufficient funds", 2)
	end
	self.balance = self.balance - v
end

function SpecialAccount:getLimit ()
	return self.limit or 0
end

s = SpecialAccount:new{limit=1000.00}
s:deposit(100.00)
s:withdraw(200.00)
print(s.balance)
