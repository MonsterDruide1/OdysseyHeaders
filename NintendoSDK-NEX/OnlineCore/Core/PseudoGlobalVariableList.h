#pragma once

#include <cstdint>

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class PseudoGlobalVariableRoot;

class PseudoGlobalVariableList : public RootObject {
public:
    PseudoGlobalVariableList();

    virtual ~PseudoGlobalVariableList();

    void AddVariable(PseudoGlobalVariableRoot*);
    void RemoveVariable(PseudoGlobalVariableRoot*);
    static PseudoGlobalVariableRoot* GetVariable(uint32_t idx);
    static uint32_t FindVariableIndex(PseudoGlobalVariableRoot*);
    void AllocateExtraContextsForAllVariables();
    void FreeExtraContextsForAllVariables();
    void ResetContextForAllVariables(uint32_t);
    static uint32_t GetNbOfVariables();

    static PseudoGlobalVariableRoot* s_pVariableListHead;
    static uint32_t m_uiNbOfVariables;
};

}  // namespace nn::nex
