#pragma once

#include "Common/Protocol.h"

namespace nn::nex {
class Credentials;
class EndPoint;
class Message;
class ProtocolCallContext;
class ProtocolRequestBrokerInterface;

class ClientProtocol : public Protocol {
public:
    ClientProtocol(u32);

    virtual ~ClientProtocol();

    virtual char* GetType() const;
    virtual bool IsAKindOf(const char*) const;
    virtual void EnforceDeclareSysComponentMacro();

    virtual Protocol::_Type GetProtocolType() const = 0;

    virtual void ExtractCallSpecificResults(Message*, ProtocolCallContext*) = 0;
    virtual ClientProtocol* CreateResponder() const = 0;
    virtual void SetDefaultCredentials(Credentials*);

    bool SendOverLocalLoopback(ProtocolCallContext*, Message*);
    bool SendRMCMessage(ProtocolCallContext*, Message*);
    void ProcessResponse(Message*, EndPoint*);

    Credentials* mCredentials;
};
}  // namespace nn::nex
