# $(addprefix prefix,name...)
# $(call valid-files, file-list)
valid-files = test -s . $(addprefix -a -s ,$1)

files:
	$(call valid-files, 01.mk 02.mk)
