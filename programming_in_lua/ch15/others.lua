function openpackage (ns)
	for n,v in pairs(ns) do
		if _G[n] ~= nil then
			error("name clash: " .. n .. " is already defined")
		end
		_G[n] = v
	end
end

openpackage(ns)
