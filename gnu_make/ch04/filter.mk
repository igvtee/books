# %he%. second % as literal character
words := he the hen other the%
get-the:
	@echo he matches: $(filter he, $(words))
	@echo %he matches: $(filter %he, $(words))
	@echo he% matches: $(filter he%, $(words))
	@echo %he% matches: $(filter %he%, $(words))

$(ui_library): $(filter ui/%.o,$(objects))
	$(AR) $(ARFLAGS) $@ $^
