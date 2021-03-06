#ls_sources := ls.c glob.c
#ls_headers := ls.h glob.h
#ls_objects := ls.o glob.o

# $(call program-variables,variable-prefix,file-list)
define program-variables
  $1_sources = $(filter %c,$2)
  $1_headers = $(filter %h,$2)
  $1_objects = $(subst .c,.o,$(filter %.c,$2))

  $$($1_objects): $$($1_headers)
endef

$(eval $(call program-variables,ls,ls.c ls.h glob.c glob.h))

ls: $(ls_objects)
