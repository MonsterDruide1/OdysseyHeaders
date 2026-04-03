#pragma once

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

    Protocol(u32);

    virtual ~Protocol();

    virtual char* GetType() const;
    virtual bool IsAKindOf(const char*) const;
    virtual void EnforceDeclareSysComponentMacro();

    virtual bool BeginInitialization();
    virtual bool BeginTermination();

    virtual Protocol::_Type GetProtocolType() const = 0;
    virtual void EndPointDisconnected(EndPoint*);
    virtual void FaultDetected(EndPoint*, u32);
    virtual Protocol* Clone() const;
    virtual bool Reload();

    EndPoint* GetOutgoingConnection() const;
    void SetIncomingConnection(EndPoint*);
    void SetProtocolID(u16);
    void AddMethodID(Message*, u32);
    void CopyMembers(const Protocol*);
    void AssociateProtocolRequestBroker(ProtocolRequestBrokerInterface*);
    void ClearFlag(u32 newFlag);

    static void ExtractProtocolKey(Message*, Protocol::_Command&, u16&);
    static bool IsOldRVDDLVersion(EndPoint*);

    u16 mProtocolID;
    u16 _4A;
    u32 _4C;
    EndPoint* mOutgoingConnection;
    ProtocolRequestBrokerInterface* mBrokerInterface;
    u32 mFlags;
    u32 _64;
    EndPoint* mIncomingConnection;
    u32 mUseLoopback;
    u32 _74;
    u64 _78;
    u32 _80;
    u32 _84;
};
}  // namespace nn::nex
