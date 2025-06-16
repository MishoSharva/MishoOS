all: os-image

# Rule to assemble the bootloader
bootloader.bin: boot.asm
	nasm -f bin boot.asm -o bootloader.bin

# Rule to compile the kernel
kernel.o: kernel.c linker.ld
	gcc -m32 -ffreestanding -c kernel.c -o kernel.o

# Rule to link the kernel into a binary
kernel.bin: kernel.o
	ld -m elf_i386 -T linker.ld kernel.o -o kernel.bin

# Rule to combine the bootloader and kernel into one image
os-image: bootloader.bin kernel.bin
	cat bootloader.bin kernel.bin > os-image

# Run the OS in QEMU
run: os-image
	qemu-system-i386 -drive format=raw,file=os-image

# Clean up the build
clean:
	rm -f *.bin *.o os-image
