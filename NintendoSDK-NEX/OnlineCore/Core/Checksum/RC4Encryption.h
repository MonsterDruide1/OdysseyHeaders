#pragma once

#include <cstdint>

#include "Core/Checksum/EncryptionAlgorithm.h"

namespace nn::nex {
class Buffer;
class Key;

class RC4Encryption : public EncryptionAlgorithm {
public:
    RC4Encryption();

    virtual ~RC4Encryption();

    virtual bool Encrypt(const Buffer&, Buffer*);
    virtual bool Encrypt(Buffer*);
    virtual bool Decrypt(const Buffer&, Buffer*);
    virtual bool Decrypt(Buffer*);

    virtual void KeyHasChanged();

    void GetDefaultKey();
    void PrepareEncryption();
    void ReinitStateArray();
    void SetReinitEverytime(bool);

    uint8_t _48[0x298 - 0x48];
};
}  // namespace nn::nex
