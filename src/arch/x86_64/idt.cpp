#include <arch/x86_64/idt.hpp>
#include <term/term.hpp>

static struct idt_entry idt_table[256];

void idt_set_gate(uint16_t num, uint64_t base, uint16_t selector, uint8_t flags) {
    idt_table[num].base0 = base;
    idt_table[num].base1 = (base >> 16) & 0xFFFF;
    idt_table[num].base2 = (base >> 32) & 0xFFFFFFFF;
    idt_table[num].selector = selector;
    idt_table[num].zero = 0;
    idt_table[num].flags = flags;
    idt_table[num].ist = 0;
}

extern "C" void asm_idt_load(idt_desc *descriptor);

void idt_reload() {
    struct idt_desc idt_descriptor;

    idt_descriptor.limit = (sizeof(idt_entry) * 256) - 1;
    idt_descriptor.base = (uint64_t)&idt_table;

    asm_idt_load(&idt_descriptor);
}

extern "C" void asm_isr0();
extern "C" void asm_isr1();
extern "C" void asm_isr2();
extern "C" void asm_isr3();
extern "C" void asm_isr4();
extern "C" void asm_isr5();
extern "C" void asm_isr6();
extern "C" void asm_isr7();
extern "C" void asm_isr8();
extern "C" void asm_isr9();
extern "C" void asm_isr10();
extern "C" void asm_isr11();
extern "C" void asm_isr12();
extern "C" void asm_isr13();
extern "C" void asm_isr14();
extern "C" void asm_isr15();
extern "C" void asm_isr16();
extern "C" void asm_isr17();
extern "C" void asm_isr18();
extern "C" void asm_isr19();

void idt_init() {
    tinfo("Initializing IDT...");

    idt_set_gate(0, (uint64_t)asm_isr0, 0x28, 0x8E);

    //TODO: Setup ISRs

    idt_reload();

    tinfo("IDT Initialized");
}