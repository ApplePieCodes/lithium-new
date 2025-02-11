#include <kmain.hpp>
#include <libc/stdint.h>
#include <term/term.h>

extern "C" void init() {
    terminal_init();
    kmain();
}