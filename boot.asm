BITS 32

global _start

_start:
    ; Set video mode (80x25 text mode)
    mov ax, 0x03       ; 0x03 is 80x25 text mode
    int 0x10           ; BIOS interrupt to change video mode

    ; Jump to the kernel at 0x1000 (address set by linker)
    jmp 0x1000         ; Jump to the kernel entry point