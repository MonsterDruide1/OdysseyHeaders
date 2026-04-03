#pragma once

#include "Platform/Core/RootObject.h"

namespace nn::nex {

class RefCountedObject : public RootObject {
public:
    RefCountedObject() {}

    virtual ~RefCountedObject() {}

public:
    u16 field_8;
};

}  // namespace nn::nex
