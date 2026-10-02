#pragma once

#include "Platform/Stack/Core/SocketDriver.h"

namespace nn::nex {

class BerkeleySocketDriver : SocketDriver {
public:
    class BerkeleySocket : public SocketDriver::Socket {
    public:
        BerkeleySocket();
        BerkeleySocket(const BerkeleySocket*, int);
        ~BerkeleySocket();

        bool Open(TransportProtocol::Type);
        bool SetAsync(bool);
        bool SetBroadcastMode(bool);
        bool Bind(uint16_t&);
        bool LastSocketErrorToResult(const char*, long);
        int32_t GetLastSocketError(long);
        int32_t RecvFrom(uint8_t*, size_t, SocketDriver::InetAddress*, uint64_t*,
                         SocketDriver::_SocketFlag);
    };

    virtual ~BerkeleySocketDriver();
};

}  // namespace nn::nex
