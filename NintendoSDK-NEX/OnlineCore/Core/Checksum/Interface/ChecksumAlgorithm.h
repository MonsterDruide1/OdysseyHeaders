#pragma once

#include <cstdint>

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class Buffer;
class SignatureBytes;

class ChecksumAlgorithm : public RootObject {
public:
    ChecksumAlgorithm();

    virtual ~ChecksumAlgorithm();

    virtual bool ComputeChecksum(const Buffer&, Buffer*) = 0;
    virtual bool ComputeChecksum(const uint8_t**, const uint64_t*, uint64_t, SignatureBytes&) = 0;
    virtual bool IsReady() const;
    virtual void ComputeChecksumForTransport(const uint8_t*, uint64_t);
    virtual uint32_t ComputeChecksumForTransportArray(const uint8_t**, const uint64_t*,
                                                      uint64_t) = 0;
    virtual uint32_t GetChecksumLength() = 0;

    uint64_t _8;
    uint8_t _10;
};

}  // namespace nn::nex
