#include <arch/x86_64/gdt.hpp>
#include <term/term.hpp>
#include <stdint.h>

static struct gdt gdt_table;

static struct tss tss_table;

struct gdt_desc gdt_descriptor;

extern "C" void asm_lgdt();
extern "C" void asm_ltr();
extern "C" void asm_load_segments();

void gdt_reload()
{
    gdt_descriptor.limit = sizeof(struct gdt) - 1;
    gdt_descriptor.base = (unsigned long)&gdt_table;

    asm_lgdt();    
}

void tss_reload()
{
    asm_ltr();
}

void gdt_init() {
    tinfo("Initializing GDT...");
    //Null Segment
    gdt_table.null.limit = 0x0000;
    gdt_table.null.base0 = 0x0000;
    gdt_table.null.base1 = 0x00;
    gdt_table.null.access = 0b00000000;
    gdt_table.null.granularity = 0b00000000;
    gdt_table.null.base2 = 0x00;
    // 16-Bit Code Segment
    gdt_table.code_16.limit = 0xFFFF;
    gdt_table.code_16.base0 = 0x0000;
    gdt_table.code_16.base1 = 0x00;
    gdt_table.code_16.access = 0b10011010;
    gdt_table.code_16.granularity = 0b00000000;
    gdt_table.code_16.base2 = 0x00;
    // 16-Bit Data Segment
    gdt_table.data_16.limit = 0xFFFF;
    gdt_table.data_16.base0 = 0x0000;
    gdt_table.data_16.base1 = 0x00;
    gdt_table.data_16.access = 0b10011010;
    gdt_table.data_16.granularity = 0b00000000;
    gdt_table.data_16.base2 = 0x00;
    // 32-Bit Code Segment
    gdt_table.code_32.limit = 0xFFFF;
    gdt_table.code_32.base0 = 0x0000;
    gdt_table.code_32.base1 = 0x00;
    gdt_table.code_32.access = 0b10011010;
    gdt_table.code_32.granularity = 0b11001111;
    gdt_table.code_32.base2 = 0x00;
    // 32-Bit Data Segment
    gdt_table.data_32.limit = 0xFFFF;
    gdt_table.data_32.base0 = 0x0000;
    gdt_table.data_32.base1 = 0x00;
    gdt_table.data_32.access = 0b10010010;
    gdt_table.data_32.granularity = 0b11001111;
    gdt_table.data_32.base2 = 0x00;
    // 64-Bit Code Segment
    gdt_table.code_64.limit = 0xFFFF;
    gdt_table.code_64.base0 = 0x0000;
    gdt_table.code_64.base1 = 0x00;
    gdt_table.code_64.access = 0b10011010;
    gdt_table.code_64.granularity = 0b00100000;
    gdt_table.code_64.base2 = 0x00;
    // 64-Bit Data Segment
    gdt_table.data_64.limit = 0xFFFF;
    gdt_table.data_64.base0 = 0x0000;
    gdt_table.data_64.base1 = 0x00;
    gdt_table.data_64.access = 0b10010010;
    gdt_table.data_64.granularity = 0b00000000;
    gdt_table.data_64.base2 = 0x00;
    // 64-Bit User Code Segment
    gdt_table.user_code_64.limit = 0xFFFF;
    gdt_table.user_code_64.base0 = 0x0000;
    gdt_table.user_code_64.base1 = 0x00;
    gdt_table.user_code_64.access = 0b11111010;
    gdt_table.user_code_64.granularity = 0b00000000;
    gdt_table.user_code_64.base2 = 0x00;
    // 64-Bit User Data Segment
    gdt_table.user_data_64.limit = 0xFFFF;
    gdt_table.user_data_64.base0 = 0x0000;
    gdt_table.user_data_64.base1 = 0x00;
    gdt_table.user_data_64.access = 0b11110010;
    gdt_table.user_data_64.granularity = 0b00100000;
    gdt_table.user_data_64.base2 = 0x00;
    gdt_table.tss.limit = sizeof(tss_table) - 1;
    gdt_table.tss.base0 = (unsigned long)&tss_table;
    gdt_table.tss.base1 = ((unsigned long)&tss_table) >> 16;
    gdt_table.tss.access = 0x89;
    gdt_table.tss.flags = 0x00;
    gdt_table.tss.base2 = ((unsigned long)&tss_table) >> 24;
    gdt_table.tss.base3 = ((unsigned long)&tss_table) >> 32;
    gdt_table.tss.reserved = 0x00;

    gdt_reload();
    tss_reload();

    asm_load_segments();

    tinfo("GDT initialized");
}