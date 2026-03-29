#pragma once

#include "Platform/Core/RootObject.h"

namespace nn::nex {

class InstanceControl;

class InstantiationContext : public RootObject {
public:
    InstantiationContext();
    InstantiationContext(InstanceControl*, u32);
    virtual ~InstantiationContext();

    void AddInstance(InstanceControl*, u32);
    void DelInstance(InstanceControl*, u32);
    void InitContext();

public:
    void* m_Context[15];
    bool byte_80;
};
}  // namespace nn::nex
