#pragma once

#include "heap/seadExpHeap.h"

namespace sead {

class ClonableExpHeap : public ExpHeap {
public:
    static ClonableExpHeap* create(size_t size, const SafeString& name, Heap* parent, s32 alignment,
                           HeapDirection direction, bool);
    static ClonableExpHeap* create(void* address, size_t size, const SafeString& name, bool);
    static ClonableExpHeap* create(void* address, size_t size, const SafeString& name, Heap* parent, bool);

    static ClonableExpHeap* tryCreate(size_t size, const SafeString& name, Heap* parent, s32 alignment,
                              HeapDirection direction, bool);
    static ClonableExpHeap* tryCreate(void* address, size_t size, const SafeString& name, bool);
    static ClonableExpHeap* tryCreate(void* address, size_t size, const SafeString& name, Heap* parent, bool);
    
    ClonableExpHeap(const SafeString& name, Heap* parent, void* address, size_t size,
            HeapDirection direction, bool flag) : ExpHeap(name, parent, address, size, direction, flag) {}

    ClonableExpHeap* clone() const;
};

}
