#pragma once

#include <cstddef>

namespace nn::nex {
class RootObject {
public:
    class TargetPool {};

    virtual ~RootObject() {}

    static void* operator new(size_t);
    static void operator delete(void*);
    static void* operator new(size_t, const char*, unsigned int);
    static void* operator new[](size_t);
    static void* operator new[](size_t, const char*, unsigned int);
    static void operator delete[](void*);
    static void operator delete(void*, const char*, unsigned int);
    static void operator delete[](void*, const char*, unsigned int);
    static void* operator new(size_t, RootObject::TargetPool);
    static void* operator new(size_t, RootObject::TargetPool, const char*, unsigned int);
};
}  // namespace nn::nex
