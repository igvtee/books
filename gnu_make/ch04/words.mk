# $(words text)
CURRENT_PATH := $(subst /, ,$(HOME))
words:
	@echo My HOME path has $(words $(CURRENT_PATH)) directories.
