define create-jar
	@echo Creating $@...
	$(RM) $(TMP_JAR_DIR)
	$(MKDIR) $(TMP_JAR_DIR)
	$(CP) -r $^ $(TMP_JAR_DIR)
	cd $(TMP_JAR_DIR) && $(JAR) $(JARFLAGS) $@ .
	$(JAR) -ufm $@ $(MANIFEST)
	$(RM) $(TMP_JAR_DIR)
endef

RM := rm -rf
MKDIR := mkdir -p

$(UI_JAR): $(UI_CLASSES)
	$(create-jar)
	@$(create-jar)
