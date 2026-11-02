#pragma once

#include <cstdint>

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class String;

class BasicCache : public RootObject {
public:
    BasicCache(const String&);
    virtual ~BasicCache();

    uint64_t _8;
    uint8_t _10;
};
}  // namespace nn::nex
