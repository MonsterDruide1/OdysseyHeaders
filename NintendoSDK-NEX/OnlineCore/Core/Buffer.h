#pragma once

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
    void operator[](u64);

    bool AppendData(const void*, u64, u64);
    bool CopyContent(void*, u64, u64) const;
    void SetDefaultBufferSize(u64);
    void GetDefaultBufferSize();
    void Initialize(u64, u8);
    void AllocateDataBuffer(u64);
    void FreeDataBuffer(u8*, u64);
    void SetHeadShiftSize(u64);
    void GetAllocateSize(u64, u64);
    void ResizeByRealSize(u64);
    void AttemptExpand(u64);
    void Swap(Buffer&);
    void ComputeCheckSum(u64, u8);
    void GetCheckSum();
    void AppendCheckSum(u8);
    void StripCheckSum();
    void IsCheckSumValid(u8);
    void Trace(u64) const;
    void ToString() const;
};

}  // namespace nn::nex
