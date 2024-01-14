CC = $//home/$(USER)/opt/cross/bin/i686-elf-gcc
C_SOURCES = kernel.c vga.c idt.c string.c isr.c io.c pic.c
OBJ = ${C_SOURCES:.c=.o}

clean:
	rm -f *.o
	rm -f *.bin

$(OBJ): $(C_SOURCES)
	$(CC) -c $(C_SOURCES) -std=gnu99 -ffreestanding -O2

kernel: $(OBJ) linker.ld ../boot/boot.o
	$(CC) -T linker.ld -o kernel.bin -ffreestanding -O2 -nostdlib ../boot/boot.o $(OBJ) -lgcc

all: kernel
	echo "kernel done"