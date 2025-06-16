# MishoOS

MishoOS is a toy x86 operating system created from scratch using Assembly and C. It boots into 32-bit protected mode and displays text using direct VGA memory access.

## Features
- Custom 16-bit bootloader
- Protected mode kernel
- VGA text output
- Runs safely in QEMU

## Requirements
- NASM
- GCC (32-bit support)
- LD
- QEMU

## Build and Run

```bash
make
make run
```

## Project Files
- `boot.asm`: Bootloader written in x86 Assembly
- `kernel.c`: C kernel running in protected mode
- `linker.ld`: Linker script for memory layout
- `Makefile`: Build instructions

## Output
Boots and displays:

```
Booting MishoOS...
Welcome to MishoOS!
```

No AI, no fluff — just clean, hand-crafted low-level code.
