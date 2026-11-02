#pragma once

#include <cstdint>

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class InstanceTable;

class InstanceControl : public RootObject {
public:
    void SetDelegatorInstance(void*);

    InstanceControl(uint32_t, uint32_t);
    virtual ~InstanceControl();

    void CreateContext();
    void DeleteContext(uint32_t);
    void AllocateExtraContexts(uint64_t);
    void FreeExtraContexts();
    void GetHighestID();
    void ContextIsValid(uint32_t);
    void FindInstanceContext(InstanceControl*, uint32_t);

public:
    uint32_t mInstanceContext;
    uint32_t mInstanceType;
    void* mDelegateInstance;
    bool mIsValidControl;
    uint8_t _19;
    uint8_t _1A;
    uint8_t _1B;

    static InstanceTable* s_oInstanceTable;
};
}  // namespace nn::nex
