#pragma once

#include "Platform/Core/RootObject.h"
#include "Platform/Core/String.h"

namespace nn::nex {

struct InetAttributes {
    char byte_8;
    char byte_9;
    u16 port;
    u32 addr;
    void* qword_10;
};

class InetAddress : public RootObject {
public:
    InetAddress();
    InetAddress(const InetAddress&);
    InetAddress(void*, u32);
    InetAddress(const char*, u16);
    InetAddress(u32, u16);
    virtual ~InetAddress();

    u64 GetKey() const;
    u16 GetPortNumber() const;
    static void EnableAutoLookup(bool);
    void Init();
    InetAddress& operator=(const InetAddress&);
    void SetAddress(const char*);
    void SetPortNumber(u16);
    void SetAddress(u32);
    void SetLocalHost();
    bool IsLocalHost() const;
    u32 GetAddress() const;
    static u32 String2Address(const char*);
    bool GetAddress(char*, u64) const;
    void SetNetworkAddress(u32);
    String GetAddressStr() const;
    void SetNetworkPortNumber(u16);
    bool GetPortNumber(char*, u32) const;
    String GetPortNumberStr() const;
    void Trace(u64) const;
    void ToStr(char*) const;
    String ToStr() const;

public:
    InetAttributes m_Attributes;

    static bool s_bAutoLookup;
};

}  // namespace nn::nex
