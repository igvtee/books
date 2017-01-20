Account = {balance = 0}
-- version 1
function Account.widthdraw (v)
	Account.balance = Account.balance - v
	print(Account.balance)
end
Account.widthdraw(100.00)

-- version 2
function Account.widthdraw (self, v)
	self.balance = self.balance - v
	print(self.balance)
end
Account.widthdraw(Account, 100.00)

-- version 3
Account = {
	balance = 0,
	widthdraw = function (self, v)
		self.balance = self.balance - v
		print(self.balance)
	end
}

function Account:deposit (v)
	self.balance = self.balance + v
end

Account.deposit(Account, 200.00)
Account:widthdraw(100.00)
