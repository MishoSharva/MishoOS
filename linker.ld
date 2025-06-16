ENTRY(_start)

SECTIONS
{
    . = 0x1000;  /* Start kernel at 0x1000 */
    .text : {
        *(.text)
    }
    .data : {
        *(.data)
    }
    .bss : {
        *(.bss)
    }
}