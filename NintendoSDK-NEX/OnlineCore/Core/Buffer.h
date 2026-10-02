#pragma once

#include <cstdint>

#include "Platform/Core/RefCountedObject.h"

namespace nn::nex {
class String;

class Buffer : public RefCountedObject {
public:
    Buffer(const Buffer&);
    Buffer(const String&);
    Buffer(Buffer&&);

    virtual ~Buffer();

    bool operator==(const Buffer&) const;
    Buffer& operator=(const Buffer&);
    Buffer& operator=(Buffer&&);
    Buffer& operator+=(const Buffer&);
    void operator+(const Buffer&);
    void operator[](uint64_t);

    bool AppendData(const void*, uint64_t, uint64_t);
    bool CopyContent(void*, uint64_t, uint64_t) const;
    void SetDefaultBufferSize(uint64_t);
    void GetDefaultBufferSize();
    void Initialize(uint64_t, uint8_t);
    void AllocateDataBuffer(uint64_t);
    void FreeDataBuffer(uint8_t*, uint64_t);
    void SetHeadShiftSize(uint64_t);
    void GetAllocateSize(uint64_t, uint64_t);
    void ResizeByRealSize(uint64_t);
    void AttemptExpand(uint64_t);
    void Swap(Buffer&);
    void ComputeCheckSum(uint64_t, uint8_t);
    void GetCheckSum();
    void AppendCheckSum(uint8_t);
    void StripCheckSum();
    void IsCheckSumValid(uint8_t);
    void Trace(uint64_t) const;
    void ToString() const;
};

}  // namespace nn::nex
