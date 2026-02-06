#ifndef ERANDOM_SHUFFLE_H
#define ERANDOM_SHUFFLE_H

#include <algorithm>
#include <random>

// A drop-in replacement for std::random_shuffle
// Usage: portable_random_shuffle(vec.begin(), vec.end());
template <typename RandomAccessIterator>
void portable_random_shuffle(RandomAccessIterator first, RandomAccessIterator last) {
    // Use thread_local to ensure thread safety and avoid re-seeding every call
    // std::random_device supplies the seed
    static thread_local std::mt19937 generator{std::random_device{}()};

    std::shuffle(first, last, generator);
}

#endif
