#pragma once

#include <cstdint>

#include "Common/Protocol.h"

namespace nn::nex {
class Credentials;
class EndPoint;
class Message;
class ProtocolCallContext;
class ProtocolRequestBrokerInterface;

class ServerProtocol : public Protocol {
public:
    ServerProtocol(uint32_t);

    virtual ~ServerProtocol();

    virtual char* GetType() const;
    virtual bool IsAKindOf(const char*) const;
    virtual void EnforceDeclareSysComponentMacro();

    virtual Protocol::_Type GetProtocolType() const = 0;

    virtual void DispatchProtocolMessage(Message*, Message*, bool*, EndPoint*) = 0;
    virtual void DispatchProtocolMessageWithAttemptCount(uint64_t, Message*, Message*, bool*, int*,
                                                         EndPoint*);
    virtual bool UseAttemptCountMethod();
};
}  // namespace nn::nex
