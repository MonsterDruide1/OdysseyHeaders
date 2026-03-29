#pragma once

#include <cstddef>
#include "Platform/Core/MemoryManager.h"
#include "nn/types.h"

namespace nn::nex {

template <typename T>
class MemAllocator {
public:
    using value_type = T;

    MemAllocator() {}

    MemAllocator(const MemAllocator<T>&) {}

    T* address(T& val) const { return val; }

    const T* address(const T& val) const { return val; }

    bool operator==(const MemAllocator<T>&) const { return true; }

    bool operator!=(const MemAllocator<T>&) const { return false; }

    T* allocate(u64 size, const void*) { return MemoryManager::Allocate(size); }

    void deallocate(void* ptr, u64) { MemoryManager::Free(ptr); }

    void construct(T* ptr, const T& other) { *ptr = other; }

    void construct(T* ptr, T&& other) { *ptr = other; }

    void destroy(T*) {}

    size_t max_size() const { return -1; }
};

}  // namespace nn::nex
