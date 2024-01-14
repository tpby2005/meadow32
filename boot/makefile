AS = $//home/$(USER)/opt/cross/bin/i686-elf-as
AS_SOURCES = boot.s
OBJ = ${AS_SOURCES:.s=.o}

clean:
	rm -f *.o

$(OBJ): $(AS_SOURCES)
	$(AS) $(AS_SOURCES) -o $@

all: $(OBJ)
	echo "boot done"