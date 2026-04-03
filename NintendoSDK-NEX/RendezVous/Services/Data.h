#pragma once

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class Data : public RootObject {
public:
    Data();

    virtual ~Data();

    bool _8;
};
}  // namespace nn::nex
