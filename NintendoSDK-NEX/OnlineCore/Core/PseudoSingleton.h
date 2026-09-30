#pragma once

#include <cstdint>

#include "Core/InstanceControl.h"

namespace nn::nex {
class PseudoSingleton : public InstanceControl {
public:
    PseudoSingleton(uint32_t);
    virtual ~PseudoSingleton();
    void SetContext(uint32_t);
    void SetContextIfRequired(uint32_t);
    void UseInstantiationContext(uint64_t);
    void UseNoInstantiationContext();
    void UsingInstantiationContext();

public:
    static bool s_bUseInstantiationContext;
};
}  // namespace nn::nex
