#pragma once

#include "Common/Protocol.h"

namespace nn::nex {
class Credentials;
class EndPoint;
class Message;
class ProtocolCallContext;
class ProtocolRequestBrokerInterface;

class ServerProtocol : public Protocol {
public:
    ServerProtocol(u32);

    virtual ~ServerProtocol();

    virtual char* GetType() const;
    virtual bool IsAKindOf(const char*) const;
    virtual void EnforceDeclareSysComponentMacro();

    virtual Protocol::_Type GetProtocolType() const = 0;

    virtual void DispatchProtocolMessage(Message*, Message*, bool*, EndPoint*) = 0;
    virtual void DispatchProtocolMessageWithAttemptCount(u64, Message*, Message*, bool*, int*,
                                                         EndPoint*);
    virtual bool UseAttemptCountMethod();
};
}  // namespace nn::nex
