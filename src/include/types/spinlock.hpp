#pragma once

#include <stdbool.h>

/// @brief Basically a bool with extra steps
class spinlock
{
    private:
        bool locked = false;
    public:
        void lock() {
            while (locked) {

            }
            locked = true;
        }
        void unlock() {
            locked = false;
        }
};