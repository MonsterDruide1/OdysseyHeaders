#pragma once

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class Buffer;
class SignatureBytes;

class ChecksumAlgorithm : public RootObject {
public:
    ChecksumAlgorithm();

    virtual ~ChecksumAlgorithm();

    virtual bool ComputeChecksum(const Buffer&, Buffer*) = 0;
    virtual bool ComputeChecksum(const u8**, const u64*, u64, SignatureBytes&) = 0;
    virtual bool IsReady() const;
    virtual void ComputeChecksumForTransport(const u8*, u64);
    virtual u32 ComputeChecksumForTransportArray(const u8**, const u64*, u64) = 0;
    virtual u32 GetChecksumLength() = 0;

    u64 _8;
    u8 _10;
};

}  // namespace nn::nex
