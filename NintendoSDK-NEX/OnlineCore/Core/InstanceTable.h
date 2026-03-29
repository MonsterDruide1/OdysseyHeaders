#pragma once

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class InstanceControl;

class InstanceTable : public RootObject {
public:
    InstanceTable();

    virtual ~InstanceTable();

    bool AddInstance(InstanceControl*, u32, u32);
    void DelInstance(InstanceControl*, u32, u32);
    u32 CreateContext();
    bool DeleteContext(u32);
    void AllocateExtraContexts(u64 size);
    void FreeExtraContexts();
    u32 GetHighestID() const;
    u32 FindInstanceContext(InstanceControl*, u32);

    u8 _0[0x94];
};
}  // namespace nn::nex
