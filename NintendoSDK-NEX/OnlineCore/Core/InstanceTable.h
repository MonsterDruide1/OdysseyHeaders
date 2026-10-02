#pragma once

#include <cstdint>

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class InstanceControl;

class InstanceTable : public RootObject {
public:
    InstanceTable();

    virtual ~InstanceTable();

    bool AddInstance(InstanceControl*, uint32_t, uint32_t);
    void DelInstance(InstanceControl*, uint32_t, uint32_t);
    uint32_t CreateContext();
    bool DeleteContext(uint32_t);
    void AllocateExtraContexts(uint64_t size);
    void FreeExtraContexts();
    uint32_t GetHighestID() const;
    uint32_t FindInstanceContext(InstanceControl*, uint32_t);

    uint8_t _0[0x94];
};
}  // namespace nn::nex
