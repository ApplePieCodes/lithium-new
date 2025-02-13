[BITS 64]

; If there's a bug later, sus this file, as it changes registers unmannaged

global asm_lgdt ; Exports the _lgdt function
extern gdt_descriptor ; Imports the gdt_descriptor variable
asm_lgdt: ; Loads the GDT
    lgdt [gdt_descriptor]
    ret

global asm_ltr ; Exports the _ltr function
asm_ltr: ; Loads the task register
    push ax
    mov ax, 0x0048 ; You have to set a register, because for some reason ltr won't take a raw hex code
    ltr ax ; Load the task register
    pop ax
    ret

global asm_load_segments
asm_load_segments:
    push ax
    mov ax, 0x0030 ; Ditto. See line asm_ltr
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    pop ax
    ret