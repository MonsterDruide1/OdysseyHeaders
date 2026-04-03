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
        bool Bind(u16&);
        bool LastSocketErrorToResult(const char*, long);
        s32 GetLastSocketError(long);
        s32 RecvFrom(u8*, ulong, SocketDriver::InetAddress*, u64*, SocketDriver::_SocketFlag);
    };

    virtual ~BerkeleySocketDriver();
};

}  // namespace nn::nex
