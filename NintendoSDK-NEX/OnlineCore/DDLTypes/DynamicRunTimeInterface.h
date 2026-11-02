#pragma once

#include <cstdint>

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class DynamicRunTimeInterface : public RootObject {
public:
    DynamicRunTimeInterface();

    virtual ~DynamicRunTimeInterface();

    uint64_t* GetInstance();
};
}  // namespace nn::nex
