#include <kmain.hpp>
#include <libc/stdint.h>
#include <term/term.h>
#include <arch/x86_64/gdt.h>

extern "C" void init() {
    terminal_init();
    kmain();
}