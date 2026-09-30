#pragma once

#include <cstdint>

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class MutexPrimitive;
class WaterMark;

class MemoryManager : public RootObject {
public:
    enum _InstructionType : uint32_t {};

    using fcnMalloc = void* (*)(unsigned long);
    using fcnFree = void* (*)(void*);

    static fcnMalloc s_fcnMalloc;
    static fcnFree s_fcnFree;
    static void* s_eShutDownState;

    MemoryManager(const char* watermarkName);

    virtual ~MemoryManager();

    virtual void BeginProtection() {}

    virtual void EndProtection() {}

    static void* Allocate(uint64_t);
    static void* GenericMalloc(uint64_t);
    static void AllocateForPbPool(void*, fcnFree, void*);
    static void Free(void*);
    static void GenericFree(fcnFree, void*);
    static void AllocateThreadSafe(uint64_t);
    static void FreeThreadSafe(void*);
    static void IncreaseMemUsage(uint64_t);
    static void DecreaseMemUsage(uint64_t);
    static void GetDefaultMemoryManager();
    static void ShutdownDefaultMemoryManager();
    static void Trace();
    const char* GetInstructionTypeString(_InstructionType) const;

public:
    int dword_8;
    WaterMark* m_pMemoryWaterMark;
    MutexPrimitive* m_pMutex;
};
}  // namespace nn::nex

extern "C" {
void* QuazalCRTAlloc(uint64_t);
void* QuazalCRTRealloc(uint64_t, void*);
void QuazalCRTFree(void*);
void* QuazalCRTCalloc(uint64_t, uint64_t);
}
