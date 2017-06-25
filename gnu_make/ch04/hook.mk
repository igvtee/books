# $(call build-library, object-files)
define build-library
  $(AR) $(ARFLAGS) $@ $1
  $(call build-library-hook,$@)
endef

$(foo_lib): build-library-hook = $(RANLIB) $1
$(foo_lib): $(foo_objects)
	$(call build-library,$^)

$(bar_lib): build-library-hook = $(CHMOD) 444 $1
$(bar_lib): $(bar_objects)
	$(call build-library,$^)

