# $(if condition,then-part,else-part)
# define COMSPEC on windows only
PATH_SEP := $(if $(COMSPEC),;,:)

# check make version
$(if $(filter $(MAKE_VERSION),3.80 3.81 3.90 3.92),,\
	$(error This makefile require one of GNU make version -.))
