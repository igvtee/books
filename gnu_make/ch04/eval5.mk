#ls_sources := ls.c glob.c
#ls_headers := ls.h glob.h
#ls_objects := ls.o glob.o

# $(call program-variables,variable-prefix,file-list)
define program-variables
  $(eval $1_sources = $(filter %c,$2))
  $(eval $1_headers = $(filter %h,$2))
  $(eval $1_objects = $(subst .c,.o,$(filter %.c,$2)))

  programs += $1

  $1: $($1_objects)

  $($1_objects): $($1_headers)
endef

$(eval $(call program-variables,ls,ls.c ls.h glob.c glob.h))
$(eval $(call program-variables,cp,cp.c cp.h glob.c glob.h))
$(eval $(call program-variables,mv,mv.c mv.h glob.c glob.h))
$(eval $(call program-variables,ln,ln.c ln.h glob.c glob.h))
$(eval $(call program-variables,rm,rm.c rm.h glob.c glob.h))

all: $(programs)
