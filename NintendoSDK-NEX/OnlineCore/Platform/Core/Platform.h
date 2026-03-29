#pragma once

#include <nn/os.h>
#include "Platform/Core/RootObject.h"

namespace nn::nex {
class ErrorDescriptionTable;

class Platform : public RootObject {
public:
    static Platform* _Instance;
    static u32 s_oRNG[];
    static bool s_bSeedIsInitialized;
    static ErrorDescriptionTable
        m_oErrorTable;  // the official symbol is named with m_ even though its static

public:
    Platform();
    virtual ~Platform();
    Platform* Instance();
    static void CreateInstance();
    static void DeleteInstance();

    void Sleep(u32);
    nn::os::Tick GetTick();
    static void NetworkToHost(const unsigned char*, u16*);
    static void NetworkToHost(const unsigned char*, u32*);
    static void NetworkToHost(const unsigned char*, u64*);
    static void HostToNetwork(const u16*, unsigned char*);
    static void HostToNetwork(const u32*, unsigned char*);
    static void HostToNetwork(const u64*, unsigned char*);
    static void WarnObsoleteMethod(const char*, const char*);
    static void SetRandomNumberSeed(u32);
    static void GetRandomNumber(u32);
    static u32 GetRandomSeed();
    static void GetRealRandomNumber(float);
    static u32 GetProcessID();
    static u64 GetPlatformID();
    static void Breakpoint();
    static void YieldThread();
};
}  // namespace nn::nex
