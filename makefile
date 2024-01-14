TARGETS = boot kernel iso

clean: $(TARGETS)
	for dir in $(TARGETS); do \
		cd $$dir; \
		make clean; \
		cd ..; \
	done

all: $(TARGETS)
	for dir in $(TARGETS); do \
		cd $$dir; \
		make all; \
		cd ..; \
	done

run: clean all
	qemu-system-i386 -cdrom iso/meadow.iso

debug: clean all
	qemu-system-i386 -cdrom iso/meadow.iso -s -S & gdb -ex "target remote localhost:1234" -ex "layout asm" -ex "layout regs"