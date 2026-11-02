#pragma once

#include <cstdint>

#include <nn/os.h>
#include "Platform/Core/RootObject.h"

namespace nn::nex {
class ErrorDescriptionTable;

class Platform : public RootObject {
public:
    static Platform* _Instance;
    static uint32_t s_oRNG[];
    static bool s_bSeedIsInitialized;
    static ErrorDescriptionTable
        m_oErrorTable;  // the official symbol is named with m_ even though its static

public:
    Platform();
    virtual ~Platform();
    Platform* Instance();
    static void CreateInstance();
    static void DeleteInstance();

    void Sleep(uint32_t);
    nn::os::Tick GetTick();
    static void NetworkToHost(const unsigned char*, uint16_t*);
    static void NetworkToHost(const unsigned char*, uint32_t*);
    static void NetworkToHost(const unsigned char*, uint64_t*);
    static void HostToNetwork(const uint16_t*, unsigned char*);
    static void HostToNetwork(const uint32_t*, unsigned char*);
    static void HostToNetwork(const uint64_t*, unsigned char*);
    static void WarnObsoleteMethod(const char*, const char*);
    static void SetRandomNumberSeed(uint32_t);
    static void GetRandomNumber(uint32_t);
    static uint32_t GetRandomSeed();
    static void GetRealRandomNumber(float);
    static uint32_t GetProcessID();
    static uint64_t GetPlatformID();
    static void Breakpoint();
    static void YieldThread();
};
}  // namespace nn::nex
