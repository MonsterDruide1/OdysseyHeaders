#pragma once

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class PseudoGlobalVariableRoot;

class PseudoGlobalVariableList : public RootObject {
public:
    PseudoGlobalVariableList();

    virtual ~PseudoGlobalVariableList();

    void AddVariable(PseudoGlobalVariableRoot*);
    void RemoveVariable(PseudoGlobalVariableRoot*);
    static PseudoGlobalVariableRoot* GetVariable(u32 idx);
    static u32 FindVariableIndex(PseudoGlobalVariableRoot*);
    void AllocateExtraContextsForAllVariables();
    void FreeExtraContextsForAllVariables();
    void ResetContextForAllVariables(u32);
    static u32 GetNbOfVariables();

    static PseudoGlobalVariableRoot* s_pVariableListHead;
    static u32 m_uiNbOfVariables;
};

}  // namespace nn::nex
