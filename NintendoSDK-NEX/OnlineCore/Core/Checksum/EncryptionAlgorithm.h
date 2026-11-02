#pragma once

#include <cstdint>

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class Buffer;
class Key;

class EncryptionAlgorithm : public RootObject {
public:
    EncryptionAlgorithm(uint32_t, uint32_t);

    virtual ~EncryptionAlgorithm();

    virtual bool Encrypt(const Buffer&, Buffer*) = 0;
    virtual bool Encrypt(Buffer*);
    virtual bool Decrypt(const Buffer&, Buffer*) = 0;
    virtual bool Decrypt(Buffer*);
    virtual bool GetErrorString(uint32_t, char* destStr, uint64_t errLen);
    virtual void KeyHasChanged();

    bool SetKey(const Key& key);

    uint64_t _8;
    uint64_t _10;
    uint64_t _18;
    uint64_t _20;
    uint64_t _28;
    uint64_t _30;
    uint64_t _38;
    uint64_t _40;
};

}  // namespace nn::nex
