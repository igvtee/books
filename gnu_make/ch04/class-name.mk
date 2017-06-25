# $(call file-to-class-name, file-name)
file-to-class-name = $(subst /,.,$(patsubst %.java,%,$1))
CALIBRATE_ELEVATOR := com/wonka/CalibrateElevator.java

# $(call file-to-root-class-name, root-dir, file-name)
file-to-root-class-name = $(subst /,., \
	$(subst .java,, \
	$(subst $1/,,$2)))
ROOT_ELEVATOR := /home/001/com/wonka/CalibrateElevator.java

JAVA := java

all: calibrate root

calibrate:
	# $(JAVA) $(call file-to-class-name,$(CALIBRATE_ELEVATOR))

root:
	# $(JAVA) $(call file-to-root-class-name,/home/001,$(ROOT_ELEVATOR))

