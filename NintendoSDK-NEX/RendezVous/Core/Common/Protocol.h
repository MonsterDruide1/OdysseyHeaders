#pragma once

#include <cstdint>

#include "Core/SystemComponent.h"

namespace nn::nex {
class Credentials;
class EndPoint;
class Message;
class ProtocolCallContext;
class ProtocolRequestBrokerInterface;

class Protocol : public SystemComponent {
public:
    enum _Command { Response, Request };

    enum _Type { Client, Server };

    Protocol(uint32_t);

    virtual ~Protocol();

    virtual char* GetType() const;
    virtual bool IsAKindOf(const char*) const;
    virtual void EnforceDeclareSysComponentMacro();

    virtual bool BeginInitialization();
    virtual bool BeginTermination();

    virtual Protocol::_Type GetProtocolType() const = 0;
    virtual void EndPointDisconnected(EndPoint*);
    virtual void FaultDetected(EndPoint*, uint32_t);
    virtual Protocol* Clone() const;
    virtual bool Reload();

    EndPoint* GetOutgoingConnection() const;
    void SetIncomingConnection(EndPoint*);
    void SetProtocolID(uint16_t);
    void AddMethodID(Message*, uint32_t);
    void CopyMembers(const Protocol*);
    void AssociateProtocolRequestBroker(ProtocolRequestBrokerInterface*);
    void ClearFlag(uint32_t newFlag);

    static void ExtractProtocolKey(Message*, Protocol::_Command&, uint16_t&);
    static bool IsOldRVDDLVersion(EndPoint*);

    uint16_t mProtocolID;
    uint16_t _4A;
    uint32_t _4C;
    EndPoint* mOutgoingConnection;
    ProtocolRequestBrokerInterface* mBrokerInterface;
    uint32_t mFlags;
    uint32_t _64;
    EndPoint* mIncomingConnection;
    uint32_t mUseLoopback;
    uint32_t _74;
    uint64_t _78;
    uint32_t _80;
    uint32_t _84;
};
}  // namespace nn::nex
