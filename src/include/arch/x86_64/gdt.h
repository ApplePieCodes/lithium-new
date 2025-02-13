#pragma once

typedef struct gdt_entry
{
    unsigned short limit;
    unsigned short base0;
    unsigned char base1;
    unsigned char access;
    unsigned char granularity;
    unsigned char base2;
} __attribute__((packed)) gdt_entry_t;

typedef struct tss_desc {
    unsigned short limit;
    unsigned short base0;
    unsigned char base1;
    unsigned char access;
    unsigned char flags;
    unsigned char base2;
    unsigned int base3;
    unsigned int reserved;
} __attribute__((packed)) tss_desc_t;

typedef struct gdt_desc {
    unsigned short limit;
    unsigned long base;
} __attribute__((packed)) gdt_desc_t;

typedef struct gdt {
    gdt_entry_t null;
    gdt_entry_t code_16;
    gdt_entry_t data_16;
    gdt_entry_t code_32;
    gdt_entry_t data_32;
    gdt_entry_t code_64;
    gdt_entry_t data_64;
    gdt_entry_t user_code_64;
    gdt_entry_t user_data_64;
    tss_desc_t tss;
} __attribute__((packed)) gdt_t;

typedef struct tss {
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
} __attribute__((packed)) tss_t;

void gdt_init();