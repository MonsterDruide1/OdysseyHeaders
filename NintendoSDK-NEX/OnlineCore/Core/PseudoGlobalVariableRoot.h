#pragma once

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class PseudoGlobalVariableList;

class PseudoGlobalVariableRoot : public RootObject {
public:
    PseudoGlobalVariableRoot();

    virtual ~PseudoGlobalVariableRoot();

    virtual void AllocateExtraContexts() = 0;
    virtual void FreeExtraContexts() = 0;
    virtual void ResetContext(u32) = 0;
    virtual PseudoGlobalVariableRoot* GetNext() = 0;
    virtual void SetNext(PseudoGlobalVariableRoot* pNextVariable) = 0;

    static void ResetContextForAllVariables(u32);
    static void AllocateExtraContextsForAllVariables(u64);
    static void FreeExtraContextsForAllVariables();
    static s64 GetNbOfExtraContexts();

    PseudoGlobalVariableRoot* mNextRoot;

    static s64 s_uiNbOfExtraContexts;
    static PseudoGlobalVariableList s_oList;
};

}  // namespace nn::nex
