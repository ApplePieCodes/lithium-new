#include <kmain.hpp>
#include <stdint.h>
#include <term/term.hpp>
#include <arch/x86_64/gdt.hpp>

extern "C" void init() {
    terminal_init();
    gdt_init();
    kmain();
}