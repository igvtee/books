# $(origin variable)
# return: undefined, default, environment, environment override,
# 	file, command line, override, automatic

# $(call assert-defined,variable-name)
define assert-defined
	$(call assert, \
	$(filter-out undefined,$(origin $1)), \
	'$1' is undefined)
endef
