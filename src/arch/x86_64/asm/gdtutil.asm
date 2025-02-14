[BITS 64] ; We want 64 bit assembly

global asm_lgdt ; Exports the _lgdt function
extern gdt_descriptor ; Imports the gdt_descriptor variable
asm_lgdt: ; Loads the GDT
    lgdt [gdt_descriptor]
    ret

global asm_ltr ; Exports the _ltr function
asm_ltr: ; Loads the task register
    push rax ; Gotta preserve rax
    mov ax, 0x0048 ; You have to set a register, because for some reason ltr won't take a raw hex code
    ltr ax ; Load the task register
    pop rax
    ret

global asm_load_segments
asm_load_segments:
    push rax ; Ditto. See asm_ltr
    mov ax, 0x0030 ; Ditto. See asm_ltr
    mov ds, ax ; Setting the segment selector registers.
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    pop rax
    ret