#pragma once

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
    void ResizeBuffer(u64);
    void TestFreeRoom(u64);
    void StreamNumber(u8);
    void AddBaseIfRequired();
    void StreamNumber(u32);
    void StreamNumber(s32);
    StringStream& operator<<(const char*);
    StringStream& operator<<(const StringStream&);
    StringStream& operator<<(bool);
    StringStream& operator<<(double);
    StringStream& operator<<(float);
    StringStream& operator<<(const void*);
    StringStream& operator<<(u64);
    StringStream& operator<<(long);
    void BytesDump(const unsigned char*, u64);
    void BytesAsciiDump(const unsigned char*, u64);

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
