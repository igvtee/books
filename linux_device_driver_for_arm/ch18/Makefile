all: template.dtb reference.dtb

%.dtb: %.dts
	dtc -I dts -O dtb $^ -o $@

.PHONY: clean
clean:
	rm *.dtb
