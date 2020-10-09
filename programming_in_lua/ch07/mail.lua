local subject = "some news"
local address = "someone@somewhere.org"

local cmd = strnig.format("mail -s '%s' '%s'", subject, address)
local f = io.popen(cmd, "w")
f:write([[
Nothing important to say.
-- me
]])
f:close()
