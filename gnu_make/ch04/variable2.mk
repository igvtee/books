release: MAKING_RELEASE = 1
release: libraries executables
...
$(foo_lib):
	$(call build-library,$^)
...
# $(call build-library, file-list)
define build-library
  $(AR) $(ARFLAGS) $A \
    $(if $(MAKING_RELEASE), \
      $(filter-out debug/%,$1), \
      $1)
endef
