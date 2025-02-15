[BITS 64]
global asm_idt_load
asm_idt_load:
    lidt [rdi]
    ret