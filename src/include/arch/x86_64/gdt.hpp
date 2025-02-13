#pragma once

#define GDT_NULL            0x00
#define GDT_CODE_16         0x08
#define GDT_DATA_16         0x10
#define GDT_CODE_32         0x18
#define GDT_DATA_32         0x20
#define GDT_CODE_64         0x28
#define GDT_DATA_64         0x30
#define GDT_USER_CODE_64    0x38
#define GDT_USER_DATA_64    0x40
#define GDT_TSS             0x48

struct gdt_entry
{
    unsigned short limit;
    unsigned short base0;
    unsigned char base1;
    unsigned char access;
    unsigned char granularity;
    unsigned char base2;
} __attribute__((packed));

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

struct gdt_desc {
    unsigned short limit;
    unsigned long base;
} __attribute__((packed));

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

#ifdef __cplusplus

extern "C" {

#endif

void gdt_init();

#ifdef __cplusplus

}

#endif