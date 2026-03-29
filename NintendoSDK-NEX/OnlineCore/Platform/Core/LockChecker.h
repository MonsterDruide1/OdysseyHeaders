#pragma once

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class LockChecker : public RootObject {
public:
    LockChecker(u32 val);
    virtual ~LockChecker();

    LockChecker(const LockChecker& other);
    void operator=(const LockChecker& other);

public:
    bool dword_8 = false;
    u32 dword_C = 0;
    u32 dword_10 = 0;
    u32 dword_14 = 0;
};
}  // namespace nn::nex
