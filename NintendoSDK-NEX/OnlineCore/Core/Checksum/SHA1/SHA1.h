#pragma once

#include <cstdint>

#include "nn/crypto.h"

namespace nn::nex {
class Sha1 {
public:
    Sha1();
    ~Sha1();
    void Init();
    void Update(const void*, uint64_t);
    void GetHash(void*, uint64_t);
    static void GenerateHash(void*, uint64_t, const void*, uint64_t);

public:
    crypto::detail::Sha1Impl* m_Sha1Impl = nullptr;
};
}  // namespace nn::nex
