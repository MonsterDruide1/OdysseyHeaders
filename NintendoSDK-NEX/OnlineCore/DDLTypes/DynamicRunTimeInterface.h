#pragma once

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class DynamicRunTimeInterface : public RootObject {
public:
    DynamicRunTimeInterface();

    virtual ~DynamicRunTimeInterface();

    u64* GetInstance();
};
}  // namespace nn::nex
