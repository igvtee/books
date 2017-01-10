local iterator	-- to be defined later
function allwords ()
	local state = {line = io.read(), pos = 1}
	return iterator, state
end
function iterator (state)
	while state.line do		-- repeat while there are lines
		-- search for next word
		local s, e = string.find(state.line, "%w+", state.pos)
		if s then		-- found a word?
			-- update next position (after this word)
			state.pos = e+1
			return string.sub(state.line, s, e)
		else		-- word not found
			state.line = io.read()		-- try next line
			state.pos = 1		-- from first position
		end
	end
	return nil
end
for word in allwords() do
	print(word)
end
