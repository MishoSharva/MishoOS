BITS 32

global inb

inb:
    mov dx, word [esp+4]    ; Move port value into dx register
    in al, dx              ; Input from port into al
    ret
