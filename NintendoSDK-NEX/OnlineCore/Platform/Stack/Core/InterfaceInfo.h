#pragma once

#include "Platform/Core/String.h"

namespace nn::nex {

class InterfaceInfo {
public:
    InterfaceInfo();
    ~InterfaceInfo();
    void SetAddress(uint32_t);
    void SetBroadcastAddress(uint32_t);
    void SetMask(uint32_t);
    void SetFlags(uint32_t);
    void SetName(char*);
    bool Addr2Str(uint32_t, char*, uint32_t);
    bool GetAddress(char*, uint32_t);
    bool GetBroadcastAddress(char*, uint32_t);
    bool GetMask(char*, uint32_t);
    bool GetName(char*, uint32_t);
    bool GetFlags(char*, uint32_t);
    uint32_t GetAddress();
    uint32_t GetBroadcastAddress();
    uint32_t GetMask();
    uint32_t GetFlags();
    const char* GetName();
    void Trace(uint64_t);

public:
    uint32_t m_Address;
    uint32_t m_BroadcastAddress;
    uint32_t m_Mask;
    uint32_t m_Flags;
    String m_Name;
};

}  // namespace nn::nex
