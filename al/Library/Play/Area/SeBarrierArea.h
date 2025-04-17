#pragma once

#include <math/seadVector.h>

#include "Library/Area/AreaObj.h"

namespace al {
class SeBarrierArea : public AreaObj {
public:
    SeBarrierArea(const char* name);

    void init(const AreaInitInfo& areaInitInfo) override;

public:
    sead::Vector3f mTrans = {0.0, 0.0, 0.0};
    bool mHasData = false;
};
}  // namespace al
