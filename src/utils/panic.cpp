#include <term/term.hpp>

void panic(const char *trigger, const char *code) {
    twrite("---LITHIUM PANIC---\n");
    twrite("Caused By:");
    twrite(trigger);
    twrite("\n");
    twrite("Error Code: ");
    twrite(code);
    asm ("cli");
    while (true) {
        asm ("hlt");
    }
}