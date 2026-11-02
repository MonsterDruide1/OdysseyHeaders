#pragma once

#include <cstdint>

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class WaterMark : public RootObject {
public:
    WaterMark(const char*, bool, uint32_t);
    virtual ~WaterMark();

public:
};
}  // namespace nn::nex
