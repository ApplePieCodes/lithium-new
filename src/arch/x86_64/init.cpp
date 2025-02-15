#include <stdint.h>

#include <kmain.hpp>
#include <term/term.hpp>
#include <arch/x86_64/gdt.hpp>
#include <arch/x86_64/idt.hpp>
#include <utils/panic.hpp>

// Extern C so limine can call it (if not C++ will name mangle)
extern "C" void init() {
    terminal_init();
    gdt_init();
    idt_init();
    int i = 0 / 0;
    kmain();
}