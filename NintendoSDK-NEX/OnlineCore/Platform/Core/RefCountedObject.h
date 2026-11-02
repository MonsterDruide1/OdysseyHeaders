#pragma once

#include <cstdint>

#include "Platform/Core/RootObject.h"

namespace nn::nex {

class RefCountedObject : public RootObject {
public:
    RefCountedObject() {}

    virtual ~RefCountedObject() {}

public:
    uint16_t field_8;
};

}  // namespace nn::nex
