#pragma once

#include "Core/PseudoGlobalVariableRoot.h"

namespace nn::nex {
template <typename T>
class PseudoGlobalVariable : public PseudoGlobalVariableRoot {
public:
    PseudoGlobalVariable();

    virtual ~PseudoGlobalVariable();

    virtual void AllocateExtraContexts();
    virtual void FreeExtraContexts();
    virtual void ResetContext(u32);
    virtual PseudoGlobalVariableRoot* GetNext();
    virtual void SetNext(PseudoGlobalVariableRoot* pNextVariable);
};
}  // namespace nn::nex
