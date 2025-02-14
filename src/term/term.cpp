#include <term/term.hpp>

#include <term/flanterm.h>
#include <term/backends/fb.h>
#include <types/spinlock.hpp>
#include <string.h>
#include <kmain.hpp>

struct flanterm_context *flanterm_ctx;
spinlock term_lock;

void terminal_init() {
    term_lock.lock();
    
    if (framebuffer_request.response->framebuffer_count < 1) {
        //TODO: Panic
    }

    struct limine_framebuffer *framebuffer = framebuffer_request.response->framebuffers[0];

    flanterm_ctx = flanterm_fb_init(NULL, NULL, (uint32_t*)framebuffer->address, framebuffer->width, framebuffer->height, framebuffer->pitch, framebuffer->red_mask_size, framebuffer->red_mask_shift, framebuffer->green_mask_size, framebuffer->green_mask_shift, framebuffer->blue_mask_size, framebuffer->blue_mask_shift, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0);

    term_lock.unlock();

    tinfo("Initializing Terminal");
    tinfo("Terminal Initialized");
}

void twrite(const char *c) {
    term_lock.lock();

    flanterm_write(flanterm_ctx, c, strlen(c));

    term_lock.unlock();
}

void tinfo(const char *c) {
    flanterm_ctx->set_text_fg_rgb(flanterm_ctx, 0xD3D7CF);
    
    twrite("[INFO] ");
    twrite(c);
    twrite("\n");
}

void twarning(const char *c) {
    flanterm_ctx->set_text_fg_rgb(flanterm_ctx, 0xC4A000);

    twrite("[WARNING] ");
    twrite(c);
    twrite("\n");
}

void terror(const char *c) {
    flanterm_ctx->set_text_fg_rgb(flanterm_ctx, 0xCC0000);

    twrite("[ERROR] ");
    twrite(c);
    twrite("\n");
}