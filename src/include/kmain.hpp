#include <limine.h>

/// @brief Framebuffer request. Used for terminal.
extern volatile struct limine_framebuffer_request framebuffer_request;

/// @brief Where stuff happens after the boot
void kmain();