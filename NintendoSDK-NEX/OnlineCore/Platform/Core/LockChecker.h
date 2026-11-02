#pragma once

#include <cstdint>

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class LockChecker : public RootObject {
public:
    LockChecker(uint32_t val);
    virtual ~LockChecker();

    LockChecker(const LockChecker& other);
    void operator=(const LockChecker& other);

public:
    bool dword_8 = false;
    uint32_t dword_C = 0;
    uint32_t dword_10 = 0;
    uint32_t dword_14 = 0;
};
}  // namespace nn::nex
