#pragma once

#include <cstdint>

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class StringStream : public RootObject {
public:
    StringStream();
    virtual ~StringStream();

    void FreeBuffer();
    long GetLength() const;
    void Clear();
    void FreeBuffer(char*);
    void ResizeBuffer(uint64_t);
    void TestFreeRoom(uint64_t);
    void StreamNumber(uint8_t);
    void AddBaseIfRequired();
    void StreamNumber(uint32_t);
    void StreamNumber(int32_t);
    StringStream& operator<<(const char*);
    StringStream& operator<<(const StringStream&);
    StringStream& operator<<(bool);
    StringStream& operator<<(double);
    StringStream& operator<<(float);
    StringStream& operator<<(const void*);
    StringStream& operator<<(uint64_t);
    StringStream& operator<<(long);
    void BytesDump(const unsigned char*, uint64_t);
    void BytesAsciiDump(const unsigned char*, uint64_t);

    char* Begin() const { return mBegin; }

    char* End() const { return mEnd; }

public:
    char* mBegin;
    long mCapacity = 0x100;
    char* mEnd;
    char mBuffer[0x100];
    bool _120;
    bool _121;
    bool _122;
    bool _123;
};
}  // namespace nn::nex
