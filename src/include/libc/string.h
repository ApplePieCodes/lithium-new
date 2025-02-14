#pragma once

#include <libc/stdint.h>
#include <libc/stddef.h>

#ifdef _cplusplus
extern "C" {
#endif

void *memcpy(void *dest, const void *src, size_t n);
void *memset(void *s, int c, size_t n);
void *memmove(void *dest, const void *src, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);
static inline int strlen(const char *c) {
    int ret = 0;
    while (*c != '\0') { // Dereference the pointer to check the character
        c++;
        ret++;
    }
    return ret;
}

#ifdef _cplusplus
}
#endif