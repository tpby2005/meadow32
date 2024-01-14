clean:
	rm -rf disk
	rm -f meadow.iso

iso: grub.cfg
	mkdir -p disk/boot/grub
	cp grub.cfg disk/boot/grub
	cp ../kernel/kernel.bin disk/boot/meadow.bin
	grub-mkrescue -o meadow.iso disk

all: iso
	echo "iso done"