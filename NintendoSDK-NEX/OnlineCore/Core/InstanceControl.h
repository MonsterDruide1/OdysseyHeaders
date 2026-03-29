#pragma once

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class InstanceTable;

class InstanceControl : public RootObject {
public:
    void SetDelegatorInstance(void*);

    InstanceControl(u32, u32);
    virtual ~InstanceControl();

    void CreateContext();
    void DeleteContext(u32);
    void AllocateExtraContexts(u64);
    void FreeExtraContexts();
    void GetHighestID();
    void ContextIsValid(u32);
    void FindInstanceContext(InstanceControl*, u32);

public:
    u32 mInstanceContext;
    u32 mInstanceType;
    void* mDelegateInstance;
    bool mIsValidControl;
    u8 _19;
    u8 _1A;
    u8 _1B;

    static InstanceTable* s_oInstanceTable;
};
}  // namespace nn::nex
