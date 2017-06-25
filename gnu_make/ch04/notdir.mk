# $(call get-java-class-name, file-name)
get-java-class-name = $(notdir $(subst .java,,$1))

$(OUT)/myfile.out: $(SRC)/source1.in $(SRC)/source2.in
	cd $(dir $@); \
	generate-myfile $^ > $(notdir $@)
