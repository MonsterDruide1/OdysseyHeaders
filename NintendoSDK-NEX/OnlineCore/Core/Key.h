#pragma once

#include <cstdint>

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class String;

class Key : public RootObject {
public:
    Key();
    Key(const uint8_t* src, uint64_t size);
    Key(uint64_t size);
    Key(const Key&);
    Key(const String&);

    virtual ~Key();

    uint64_t* GetContentPtr();
    uint64_t GetLength() const;
    Key& operator=(const Key&);
    bool operator==(const Key&);
    bool operator!=(const Key&);
    void PrepareContentPtr(uint64_t);
    String* ToString();
    void ExtractToString(String*) const;
    void Trace(uint64_t) const;
    void GenerateRandomKey(uint64_t);

    uint64_t* mContentPtrStart;  // _10
    uint64_t* mContentPtrEnd;    // _18
};
}  // namespace nn::nex
