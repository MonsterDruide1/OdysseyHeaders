#pragma once

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class String;

class BasicCache : public RootObject {
public:
    BasicCache(const String&);
    virtual ~BasicCache();

    u64 _8;
    u8 _10;
};
}  // namespace nn::nex
