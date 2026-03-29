#pragma once

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class LogFilter : public RootObject {
public:
    virtual bool OutputCurrentTrace() = 0;
};
}  // namespace nn::nex
