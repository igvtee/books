$(config): $(config_template)
	if [ ! -d $(dir $@) ]; \
	then \
	  $(MKDIR) $(dir $@); \
	else
	  true; \
	fi
	$(M4) $^ > $@
