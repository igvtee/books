#ls_sources := ls.c glob.c
#ls_headers := ls.h glob.h
#ls_objects := ls.o glob.o

# $(call program-variables, variable-prefix, file-list)
define program-variables
  $1_sources = $(filter %c,$2)
  $1_headers = $(filter %h,$2)
  $1_objects = $(subst .c,.o,$(filter %.c,$2))
endef

#$(call program-variables, ls, ls.c ls.h glob.c glob.h)
$(eval $(call program-variables, ls, ls.c ls.h glob.c glob.h))

show-variables:
	# $(ls_sources)
	# $(ls_headers)
	# $(ls_objects)
