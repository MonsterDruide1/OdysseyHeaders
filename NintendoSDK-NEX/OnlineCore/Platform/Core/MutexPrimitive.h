#pragma once

#include <nn/os/os_MutexTypes.h>
#include "Platform/Core/NonCopyable.h"
#include "Platform/Core/RootObject.h"

namespace nn::nex {
class MutexPrimitive : public RootObject, public NonCopyable {
public:
    MutexPrimitive(bool unk);
    virtual ~MutexPrimitive();

public:
    os::MutexType m_MutexType;
};
}  // namespace nn::nex
