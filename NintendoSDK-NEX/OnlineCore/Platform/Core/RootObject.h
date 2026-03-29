#pragma once

#include <nn/types.h>

namespace nn::nex {
class RootObject {
public:
    class TargetPool {};

    virtual ~RootObject() {}

    static void* operator new(ulong);
    static void operator delete(void*);
    static void* operator new(ulong, const char*, unsigned int);
    static void* operator new[](ulong);
    static void* operator new[](ulong, const char*, unsigned int);
    static void operator delete[](void*);
    static void operator delete(void*, const char*, unsigned int);
    static void operator delete[](void*, const char*, unsigned int);
    static void* operator new(ulong, RootObject::TargetPool);
    static void* operator new(ulong, RootObject::TargetPool, const char*, unsigned int);
};
}  // namespace nn::nex
