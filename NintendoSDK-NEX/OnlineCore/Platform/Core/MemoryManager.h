#pragma once

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class MutexPrimitive;
class WaterMark;

class MemoryManager : public RootObject {
public:
    enum _InstructionType : u32 {};

    using fcnMalloc = void* (*)(unsigned long);
    using fcnFree = void* (*)(void*);

    static fcnMalloc s_fcnMalloc;
    static fcnFree s_fcnFree;
    static void* s_eShutDownState;

    MemoryManager(const char* watermarkName);

    virtual ~MemoryManager();
    virtual void BeginProtection();
    virtual void EndProtection();
    static void* Allocate(u64);
    static void* GenericMalloc(u64);
    static void AllocateForPbPool(void*, fcnFree, void*);
    static void Free(void*);
    static void GenericFree(fcnFree, void*);
    static void AllocateThreadSafe(u64);
    static void FreeThreadSafe(void*);
    static void IncreaseMemUsage(u64);
    static void DecreaseMemUsage(u64);
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
void* QuazalCRTAlloc(u64);
void* QuazalCRTRealloc(u64, void*);
void QuazalCRTFree(void*);
void* QuazalCRTCalloc(u64, u64);
}
