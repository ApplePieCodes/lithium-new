#pragma once

#include <term/term.hpp>
#include <stdint.h>

/// @brief GDT Entry
struct gdt_entry
{
    unsigned short limit;
    unsigned short base0;
    unsigned char base1;
    unsigned char access;
    unsigned char granularity;
    unsigned char base2;
} __attribute__((packed));

/// @brief TSS Descriptor
struct tss_desc {
    unsigned short limit;
    unsigned short base0;
    unsigned char base1;
    unsigned char access;
    unsigned char flags;
    unsigned char base2;
    unsigned int base3;
    unsigned int reserved;
} __attribute__((packed));

/// @brief GDT Descriptor
struct gdt_desc {
    unsigned short limit;
    unsigned long base;
} __attribute__((packed));

/// @brief Represents the GDT
struct gdt {
    struct gdt_entry null;
    struct gdt_entry code_16;
    struct gdt_entry data_16;
    struct gdt_entry code_32;
    struct gdt_entry data_32;
    struct gdt_entry code_64;
    struct gdt_entry data_64;
    struct gdt_entry user_code_64;
    struct gdt_entry user_data_64;
    struct tss_desc tss;
} __attribute__((packed));

/// @brief Represents The TSS
struct tss {
    unsigned int reserved0;
    unsigned long rsp0;
    unsigned long rsp1;
    unsigned long rsp2;
    unsigned long reserved1_2;
    unsigned long ist1;
    unsigned long ist2;
    unsigned long ist3;
    unsigned long ist4;
    unsigned long ist5;
    unsigned long ist6;
    unsigned long ist7;
    unsigned long reserved3_4;
    unsigned short reserved5;
    unsigned short IOPB;
} __attribute__((packed));

/// @brief Initializes the GDT
void gdt_init();