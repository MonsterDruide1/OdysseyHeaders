#pragma once

#include "Platform/Core/String.h"
#include "nn/types.h"

namespace nn::nex {

class InterfaceInfo {
public:
    InterfaceInfo();
    ~InterfaceInfo();
    void SetAddress(u32);
    void SetBroadcastAddress(u32);
    void SetMask(u32);
    void SetFlags(u32);
    void SetName(char*);
    bool Addr2Str(u32, char*, u32);
    bool GetAddress(char*, u32);
    bool GetBroadcastAddress(char*, u32);
    bool GetMask(char*, u32);
    bool GetName(char*, u32);
    bool GetFlags(char*, u32);
    u32 GetAddress();
    u32 GetBroadcastAddress();
    u32 GetMask();
    u32 GetFlags();
    const char* GetName();
    void Trace(u64);

public:
    u32 m_Address;
    u32 m_BroadcastAddress;
    u32 m_Mask;
    u32 m_Flags;
    String m_Name;
};

}  // namespace nn::nex
