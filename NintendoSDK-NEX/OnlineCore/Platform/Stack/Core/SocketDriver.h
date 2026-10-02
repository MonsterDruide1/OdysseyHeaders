#pragma once

#include <arpa/inet.h>
#include <sys/socket.h>
#include "Platform/Core/RootObject.h"

namespace nn::nex {
class TransportProtocol {
public:
    enum Type {
        Sock_Default = 0,
        Sock_Stream = SOCK_STREAM,
        Sock_DGram = SOCK_DGRAM,
        Sock_Raw = SOCK_RAW,
        Sock_SeqPacket = SOCK_SEQPACKET,
        Sock_NonBlock = SOCK_NONBLOCK
    };
};

class SocketDriver : RootObject {
public:
    typedef in_addr_t InetAddress;

    enum _SocketFlag : int32_t {
        Msg_None = 0,
        Msg_Oob = MSG_OOB,
        Msg_Peek = MSG_PEEK,
        Msg_DontRoute = MSG_DONTROUTE,
        Msg_Eor = MSG_EOR,
        Msg_Trunc = MSG_TRUNC,
        Msg_CTrunc = MSG_CTRUNC,
        Msg_WaitAll = MSG_WAITALL,
        Msg_DontWait = MSG_DONTWAIT,
        // Msg_Eof = MSG_EOF,
        // Msg_Notification = MSG_NOTIFICATION,
        // Msg_Nbio = MSG_NBIO,
        // Msg_Compat = MSG_COMPAT,
        // Msg_SoCallbck = MSG_SOCALLBCK,
        // Msg_NoSignal = MSG_NOSIGNAL,
        Msg_CMsg_CloExec = MSG_CMSG_CLOEXEC
    };

    class Socket {
        virtual bool Open(TransportProtocol::Type);
        virtual void Close();
        virtual bool Bind(uint16_t&);
        virtual int32_t RecvFrom(uint8_t*, size_t, InetAddress*, size_t*,
                                 SocketDriver::_SocketFlag);
        virtual int32_t SendTo(const uint8_t*, size_t, const SocketDriver::InetAddress&, size_t*);
    };

    class PollInfo {};

    ~SocketDriver() override;

    virtual Socket* Create();
    virtual void Delete(Socket*);
    virtual int Poll(PollInfo*, uint32_t, uint32_t);
    virtual bool CanUseGetAllReceivableSockets();
    virtual void GetAllReceivableSockets(Socket**, size_t, uint32_t);
};

class ClientWebSocketDriver : SocketDriver {
    class ClientWebSocket : Socket {};

    ~ClientWebSocketDriver() override;
};
}  // namespace nn::nex
