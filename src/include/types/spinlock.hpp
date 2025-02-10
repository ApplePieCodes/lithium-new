#pragma once
#include <atomic>

class spinlock
{
    private:
        std::atomic<bool> locked = false;
    public:
        void lock() {
            bool expected = false;
            while (!locked.compare_exchange_strong(expected, true, std::memory_order_acquire)) {
                expected = false;
            }
        }
        void unlock() {
            locked.store(false, std::memory_order_release);
        }
};