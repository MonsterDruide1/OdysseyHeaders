#pragma once

#include "Core/InstanceControl.h"

namespace nn::nex {
class PseudoSingleton : public InstanceControl {
public:
    PseudoSingleton(u32);
    virtual ~PseudoSingleton();
    void SetContext(u32);
    void SetContextIfRequired(u32);
    void UseInstantiationContext(u64);
    void UseNoInstantiationContext();
    void UsingInstantiationContext();

public:
    static bool s_bUseInstantiationContext;
};
}  // namespace nn::nex
