#pragma once

#include <cstdint>

#include <nn/crypto.h>
#include "Platform/Core/RootObject.h"

namespace nn::nex {
class MD5 : public nn::crypto::detail::Md5Impl, public RootObject {
public:
    MD5();

    void init();
    void raw_digest(uint8_t*);
    void hex_digest();

    uint8_t _5C[0x74 - 0x5C];
};
}  // namespace nn::nex
