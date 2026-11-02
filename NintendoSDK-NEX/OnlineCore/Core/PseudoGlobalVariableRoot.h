#pragma once

#include <cstdint>

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class PseudoGlobalVariableList;

class PseudoGlobalVariableRoot : public RootObject {
public:
    PseudoGlobalVariableRoot();

    virtual ~PseudoGlobalVariableRoot();

    virtual void AllocateExtraContexts() = 0;
    virtual void FreeExtraContexts() = 0;
    virtual void ResetContext(uint32_t) = 0;
    virtual PseudoGlobalVariableRoot* GetNext() = 0;
    virtual void SetNext(PseudoGlobalVariableRoot* pNextVariable) = 0;

    static void ResetContextForAllVariables(uint32_t);
    static void AllocateExtraContextsForAllVariables(uint64_t);
    static void FreeExtraContextsForAllVariables();
    static int64_t GetNbOfExtraContexts();

    PseudoGlobalVariableRoot* mNextRoot;

    static int64_t s_uiNbOfExtraContexts;
    static PseudoGlobalVariableList s_oList;
};

}  // namespace nn::nex
