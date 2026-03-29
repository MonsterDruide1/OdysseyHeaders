#pragma once

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class LogDevice : public RootObject {
public:
    virtual ~LogDevice();
    virtual void Output(const char*);
};
}  // namespace nn::nex
