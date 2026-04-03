#pragma once

#include "Platform/Core/RootObject.h"

namespace nn::nex {

class ThreadVariableRoot : public RootObject {
public:
    virtual ~ThreadVariableRoot();
    virtual void ResetValues();
    virtual void ClearValue();
    virtual void ClearValue(unsigned long);
};

}  // namespace nn::nex
