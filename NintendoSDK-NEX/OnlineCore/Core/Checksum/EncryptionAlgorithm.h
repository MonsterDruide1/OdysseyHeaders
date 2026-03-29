#pragma once

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class Buffer;
class Key;

class EncryptionAlgorithm : public RootObject {
public:
    EncryptionAlgorithm(u32, u32);

    virtual ~EncryptionAlgorithm();

    virtual bool Encrypt(const Buffer&, Buffer*) = 0;
    virtual bool Encrypt(Buffer*);
    virtual bool Decrypt(const Buffer&, Buffer*) = 0;
    virtual bool Decrypt(Buffer*);
    virtual bool GetErrorString(u32, char* destStr, u64 errLen);
    virtual void KeyHasChanged();

    bool SetKey(const Key& key);

    u64 _8;
    u64 _10;
    u64 _18;
    u64 _20;
    u64 _28;
    u64 _30;
    u64 _38;
    u64 _40;
};

}  // namespace nn::nex
