EXPDATA := expdata 
export EXPDATA2 := expdata2

.PHONY: all
all:
	@echo $$MAKEFLAGS
	@echo $$MFLAGS
	@echo $$MAKELEVEL
	@echo $$EXPDATA
	@echo $$EXPDATA2
