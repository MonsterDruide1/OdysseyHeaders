#pragma once

#include "Library/Area/AreaObj.h"

namespace al {
class SePlayArea : public AreaObj {
public:
    SePlayArea(const char* name);

    void init(const AreaInitInfo& areaInitInfo) override;

public:
    const char* mSePlayName = nullptr;
};
}  // namespace al
