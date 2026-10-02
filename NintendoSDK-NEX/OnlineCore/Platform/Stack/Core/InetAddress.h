#pragma once

#include "Platform/Core/RootObject.h"
#include "Platform/Core/String.h"

namespace nn::nex {

struct InetAttributes {
    char byte_8;
    char byte_9;
    uint16_t port;
    uint32_t addr;
    void* qword_10;
};

class InetAddress : public RootObject {
public:
    InetAddress();
    InetAddress(const InetAddress&);
    InetAddress(void*, uint32_t);
    InetAddress(const char*, uint16_t);
    InetAddress(uint32_t, uint16_t);
    virtual ~InetAddress();

    uint64_t GetKey() const;
    uint16_t GetPortNumber() const;
    static void EnableAutoLookup(bool);
    void Init();
    InetAddress& operator=(const InetAddress&);
    void SetAddress(const char*);
    void SetPortNumber(uint16_t);
    void SetAddress(uint32_t);
    void SetLocalHost();
    bool IsLocalHost() const;
    uint32_t GetAddress() const;
    static uint32_t String2Address(const char*);
    bool GetAddress(char*, uint64_t) const;
    void SetNetworkAddress(uint32_t);
    String GetAddressStr() const;
    void SetNetworkPortNumber(uint16_t);
    bool GetPortNumber(char*, uint32_t) const;
    String GetPortNumberStr() const;
    void Trace(uint64_t) const;
    void ToStr(char*) const;
    String ToStr() const;

public:
    InetAttributes m_Attributes;

    static bool s_bAutoLookup;
};

}  // namespace nn::nex
