# $(basename name...)
# $(call file-to-class-name, root-directory, file-name)
file-to-class-name := $(subst /,., \
	$(basename \
	$(subst $1/,,$2)))

# $(call get-java-class-name, file-name)
get-java-class-name = $(notdir $(basename $1))
