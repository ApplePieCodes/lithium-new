[BITS 64]

%macro SAVE_REGISTERS 0
    push rax
    push rbx
    push rcx
    push rdx
    push rsi
    push rdi
    push rbp
    push r8
    push r9
    push r10
    push r11
    push r12
    push r13
    push r14
    push r15
%endmacro

%macro RESTORE_REGISTERS 0
    pop r15
    pop r14
    pop r13
    pop r12
    pop r11
    pop r10
    pop r9
    pop r8
    pop rbp
    pop rdi
    pop rsi
    pop rdx
    pop rcx
    pop rbx
    pop rax
%endmacro

global asm_isr0
extern isr0
asm_isr0:
    cli
    SAVE_REGISTERS
    call isr0
    RESTORE_REGISTERS
    sti
    iretq

global asm_isr1
extern isr1
asm_isr1:
    cli
    SAVE_REGISTERS
    call isr1
    RESTORE_REGISTERS
    sti
    iretq

global asm_isr2
extern isr2
asm_isr2:
    cli
    SAVE_REGISTERS
    call isr2
    RESTORE_REGISTERS
    sti
    iretq

global asm_isr3
extern isr3
asm_isr3:
    cli
    SAVE_REGISTERS
    call isr3
    RESTORE_REGISTERS
    sti
    iretq

global asm_isr4
extern isr4
asm_isr4:
    cli
    SAVE_REGISTERS
    call isr4
    RESTORE_REGISTERS
    sti
    iretq

global asm_isr5
extern isr5
asm_isr5:
    cli
    SAVE_REGISTERS
    call isr5
    RESTORE_REGISTERS
    sti
    iretq

global asm_isr6
extern isr6
asm_isr6:
    cli
    SAVE_REGISTERS
    call isr6
    RESTORE_REGISTERS
    sti
    iretq

global asm_isr7
extern isr7
asm_isr7:
    cli
    SAVE_REGISTERS
    call isr7
    RESTORE_REGISTERS
    sti
    iretq

global asm_isr8
extern isr8
asm_isr8:
    cli
    SAVE_REGISTERS
    call isr8
    RESTORE_REGISTERS
    sti
    iretq

global asm_isr9
extern isr9
asm_isr9:
    cli
    SAVE_REGISTERS
    call isr9
    RESTORE_REGISTERS
    sti
    iretq

global asm_isr10
extern isr10
asm_isr10:
    cli
    SAVE_REGISTERS
    call isr10
    RESTORE_REGISTERS
    sti
    iretq

global asm_isr11
extern isr11
asm_isr11:
    cli
    SAVE_REGISTERS
    call isr11
    RESTORE_REGISTERS
    sti
    iretq

global asm_isr12
extern isr12
asm_isr12:
    cli
    SAVE_REGISTERS
    call isr12
    RESTORE_REGISTERS
    sti
    iretq

global asm_isr13
extern isr13
asm_isr13:
    cli
    SAVE_REGISTERS
    call isr13
    RESTORE_REGISTERS
    sti
    iretq

global asm_isr14
extern isr14
asm_isr14:
    cli
    SAVE_REGISTERS
    call isr14
    RESTORE_REGISTERS
    sti
    iretq

global asm_isr15
extern isr15
asm_isr15:
    cli
    SAVE_REGISTERS
    call isr15
    RESTORE_REGISTERS
    sti
    iretq

global asm_isr16
extern isr16
asm_isr16:
    cli
    SAVE_REGISTERS
    call isr16
    RESTORE_REGISTERS
    sti
    iretq

global asm_isr17
extern isr17
asm_isr17:
    cli
    SAVE_REGISTERS
    call isr17
    RESTORE_REGISTERS
    sti
    iretq

global asm_isr18
extern isr18
asm_isr18:
    cli
    SAVE_REGISTERS
    call isr18
    RESTORE_REGISTERS
    sti
    iretq

global asm_isr19
extern isr19
asm_isr19:
    cli
    SAVE_REGISTERS
    call isr19
    RESTORE_REGISTERS
    sti
    iretq