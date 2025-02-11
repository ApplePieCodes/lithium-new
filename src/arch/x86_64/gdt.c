#include <arch/x86_64/gdt.h>

void gdt_init() {
    gdt_table = (gdt_t){
        .null = (gdt_entry_t){
            .limit = 0x0000,
            .base0 = 0x0000,
            .base1 = 0x00,
            .access = 0b00000000,
            .granularity = 0b00000000,
            .base2 = 0x00
        },
        // 16-Bit Code Segment
        .code_16 = (gdt_entry_t){
            .limit = 0xFFFF,
            .base0 = 0x0000,
            .base1 = 0x00,
            .access = 0b10011010,
            .granularity = 0b00000000,
            .base2 = 0x00
        },
        // 16-Bit Data Segment
        .data_16 = (gdt_entry_t){
            .limit = 0xFFFF,
            .base0 = 0x0000,
            .base1 = 0x00,
            .access = 0b10010010,
            .granularity = 0b00000000,
            .base2 = 0x00
        },
        // 32-Bit Code Segment
        .code_32 = (gdt_entry_t){
            .limit = 0xFFFF,
            .base0 = 0x0000,
            .base1 = 0x00,
            .access = 0b10011010,
            .granularity = 0b11001111,
            .base2 = 0x00
        },
        // 32-Bit Data Segment
        .data_32 = (gdt_entry_t){
            .limit = 0xFFFF,
            .base0 = 0x0000,
            .base1 = 0x00,
            .access = 0b10010010,
            .granularity = 0b11001111,
            .base2 = 0x00
        },
        // 64-Bit Code Segment
        .code_64 = (gdt_entry_t){
            .limit = 0x0000,
            .base0 = 0x0000,
            .base1 = 0x00,
            .access = 0b10011010,
            .granularity = 0b00100000,
            .base2 = 0x00
        },
        // 64-Bit Data Segment
        .data_64 = (gdt_entry_t){
            .limit = 0x0000,
            .base0 = 0x0000,
            .base1 = 0x00,
            .access = 0b10010010,
            .granularity = 0b00000000,
            .base2 = 0x00
        },
        // 64-Bit User Code Segment
        .user_code_64 = (gdt_entry_t){
            .limit = 0x0000,
            .base0 = 0x0000,
            .base1 = 0x00,
            .access = 0b11111010,
            .granularity = 0b00000000,
            .base2 = 0x00
        },
        // 64-Bit User Data Segment
        .user_data_64 = (gdt_entry_t){
            .limit = 0x0000,
            .base0 = 0x0000,
            .base1 = 0x00,
            .access = 0b11110010,
            .granularity = 0b00100000,
            .base2 = 0x00
        },
        // TSS Segment
        .tss = (tss_desc_t){
            .limit = sizeof(tss_table) - 1,  // FIXED: Correct limit calculation
            .base0 = (unsigned long)&tss_table,
            .base1 = ((unsigned long)&tss_table) >> 16,
            .access = 0x89, // Available TSS
            .flags = 0x00,
            .base2 = ((unsigned long)&tss_table) >> 24,
            .base3 = ((unsigned long)&tss_table) >> 32,
            .reserved = 0x00
        }
    };
}