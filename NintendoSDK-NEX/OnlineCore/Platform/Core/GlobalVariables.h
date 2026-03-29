#pragma once

#include <nn/mem.h>
#include "Platform/Core/RefCountedObject.h"
#include "Platform/Core/ThreadVariable.h"

namespace nn::nex {

class GlobalVariables : public RefCountedObject {
public:
    static GlobalVariables* s_pGv;

    nn::mem::StandardAllocator* getStandardAllocator() const { return m_Allocator; }

    ThreadVariable<unsigned int>& getLastError() { return m_LastError; }

    ThreadVariable<unsigned int>& getLastExtError() { return m_LastExtError; }

public:
    void* filler[2];
    ThreadVariable<unsigned int> m_LastError;
    void* filler2[15];
    ThreadVariable<unsigned int> m_LastExtError;
    void* filler3[51];
    nn::mem::StandardAllocator* m_Allocator;
};
}  // namespace nn::nex
