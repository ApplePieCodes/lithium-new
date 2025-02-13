#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void terminal_init();
void twrite(const char *c);
void tinfo(const char *c);
void twarning(const char *c);
void terror(const char *c);


#ifdef __cplusplus
}
#endif