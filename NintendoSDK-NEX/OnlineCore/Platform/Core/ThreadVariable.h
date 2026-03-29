#pragma once

#include "Platform/Core/ThreadVariableRoot.h"

namespace nn::nex {

template <typename T>
class ThreadVariable : public ThreadVariableRoot {
public:
    virtual ~ThreadVariable();
    virtual void ResetValues();
    virtual void ClearValue();
    virtual void ClearValue(unsigned long);

    T& GetRef();
    T& operator=(const T&);
};

}  // namespace nn::nex
