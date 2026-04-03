#pragma once

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class String;

class Key : public RootObject {
public:
    Key();
    Key(const u8* src, u64 size);
    Key(u64 size);
    Key(const Key&);
    Key(const String&);

    virtual ~Key();

    u64* GetContentPtr();
    u64 GetLength() const;
    Key& operator=(const Key&);
    bool operator==(const Key&);
    bool operator!=(const Key&);
    void PrepareContentPtr(u64);
    String* ToString();
    void ExtractToString(String*) const;
    void Trace(u64) const;
    void GenerateRandomKey(u64);

    u64* mContentPtrStart;  // _10
    u64* mContentPtrEnd;    // _18
};
}  // namespace nn::nex
