#pragma once

#include <stdbool.h>

typedef struct lock {
    bool locked;
} lock_t;

static inline void spinlock_lock(lock_t *lock) {
    while (lock->locked) {

    }
    lock->locked = true;
}

static inline void spinlock_unlock(lock_t *lock) {
    lock->locked = false;
}