#include <stdint.h>

#include <kmain.hpp>
#include <term/term.hpp>
#include <arch/x86_64/gdt.hpp>

// Extern C so limine can call it (if not C++ will name mangle)
extern "C" void init() {
    terminal_init();
    gdt_init();
    kmain();
}