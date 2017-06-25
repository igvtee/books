# $(error text)
# $(call assert,condition,message)
define assert
	$(if $1,,$(error Assertion failed: $2))
endef

# $(call assert-file-exists,wildcard-pattern)
define assert-file-exists
	$(call assert,$(wildcard $1),$1 dose not exist)
endef

# $(call assert-not-null,make-variable)
define assert-not-null
	$(call assert,$($1),The variable "$1" is null)
endef

error-exit:
	$(call assert-not-null,NON_EXISTENT)

NO_SPACE_MSG := No space left on device.
NO_FILE_MSG := File not found.
STATUS_MSG := NO_SPACE_MSG
$(error $($(STATUS_MSG)))
