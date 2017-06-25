# target- and pattern- specific variables

gui.o: CPPFLAGS += -DUSE_NEW_MALLOC=1
gui.o: gui.h
	$(COMPILE.c) $(OUTPUT_OPTION) $<
