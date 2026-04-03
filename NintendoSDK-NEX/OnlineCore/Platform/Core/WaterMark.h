#pragma once

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class WaterMark : public RootObject {
public:
    WaterMark(const char*, bool, u32);
    virtual ~WaterMark();

public:
};
}  // namespace nn::nex
