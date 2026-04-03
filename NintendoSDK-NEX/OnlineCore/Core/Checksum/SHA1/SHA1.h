#pragma once

#include "nn/crypto.h"

namespace nn::nex {
class Sha1 {
public:
    Sha1();
    ~Sha1();
    void Init();
    void Update(const void*, u64);
    void GetHash(void*, u64);
    static void GenerateHash(void*, u64, const void*, u64);

public:
    crypto::detail::Sha1Impl* m_Sha1Impl = nullptr;
};
}  // namespace nn::nex
