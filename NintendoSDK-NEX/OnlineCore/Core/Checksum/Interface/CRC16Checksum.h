#pragma once

#include <cstdint>

#include "Core/Checksum/Interface/ChecksumAlgorithm.h"

namespace nn::nex {
class Buffer;

class CRC16Checksum : public ChecksumAlgorithm {
public:
    CRC16Checksum();

    virtual ~CRC16Checksum();

    virtual bool ComputeChecksum(const Buffer&, Buffer*);
    virtual uint32_t ComputeChecksumForTransportArray(const uint8_t**, const uint64_t*, uint64_t);
    virtual uint32_t GetChecksumLength();
};

}  // namespace nn::nex
