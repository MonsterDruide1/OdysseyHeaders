#pragma once

#include <cstdint>

#include "Platform/Core/RootObject.h"

namespace nn::nex {

class InstanceControl;

class InstantiationContext : public RootObject {
public:
    InstantiationContext();
    InstantiationContext(InstanceControl*, uint32_t);
    virtual ~InstantiationContext();

    void AddInstance(InstanceControl*, uint32_t);
    void DelInstance(InstanceControl*, uint32_t);
    void InitContext();

public:
    void* m_Context[15];
    bool byte_80;
};
}  // namespace nn::nex
