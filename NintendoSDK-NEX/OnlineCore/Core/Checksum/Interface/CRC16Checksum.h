#pragma once

#include "Core/Checksum/Interface/ChecksumAlgorithm.h"

namespace nn::nex {
class Buffer;

class CRC16Checksum : public ChecksumAlgorithm {
public:
    CRC16Checksum();

    virtual ~CRC16Checksum();

    virtual bool ComputeChecksum(const Buffer&, Buffer*);
    virtual u32 ComputeChecksumForTransportArray(const u8**, const u64*, u64);
    virtual u32 GetChecksumLength();
};

}  // namespace nn::nex
