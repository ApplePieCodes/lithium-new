#include <utils/panic.hpp>

extern "C" void isr0() { // Divide By 0
    //TODO: Handle this gracefully.
}

extern "C" void isr1() { // Debugging Event
    //TODO: Impliment Debugging
}

extern "C" void isr2() { // Non-Maskable Interrupt
    //TODO: Non-Maskable Interrupt
}

extern "C" void isr3() { // Breakpoint
    //TODO: Impliment Debugging
}

extern "C" void isr4() { // INTO Overflow
    //TODO: Impliment Handing for whatever this is
}

extern "C" void isr5() { // BOUND Range Exceeded
    //TODO Impliment Handing for whatever this is
}

extern "C" void isr6() { // Invalid Opcode
    //TODO: Impliment handling for this
}

extern "C" void isr7() { // Device not avalible
    //TODO: Impliment Handling
}

extern "C" void isr8() { // Double fault
    //TODO: Impliment
}

extern "C" void isr9() { //Legacy, Does nothing
    //TODO: Maybe add like a syscall or something
}

extern "C" void isr10() { //Invalid TSS
    //TODO: Impliment
}

extern "C" void isr11() { //Invalid Segment
    //TODO: Impliment
}

extern "C" void isr12() { // IsR for stack segment fault
    //TODO: Impliment
}

extern "C" void isr13() { // ISR for General Protection fault
    //TODO: impliment
}

extern "C" void isr14() { // Page Fault
    //TODO: Impliment
}

extern "C" void isr15() { // Unused, Maybe Syscall or smthn
    //TODO: Impliment
}

extern "C" void isr16() { // Ix86 Exception
    //TODO: impliment
}

extern "C" void isr17() { // Alignment Check
    //TODO: Impliment
}

extern "C" void isr18() { // Machine Check
    //TODO: Impliment
}

extern "C" void isr19() { // SIMD Exception
    //TODO: impliment
}