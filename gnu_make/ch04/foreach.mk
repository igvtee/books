# $(foreach variable,list,body)
letters := $(foreach letter,a b c d,$(letter))
show-words:
	# letters has $(words $(letters)) words: '$(letters)'

VARIABLE_LIST := SOURCES OBJECTS HOME
$(foreach i,$(VARIABLE_LIST), \
	$(if $($i),, \
	$(shell echo $i has no value > /dev/stderr)))
