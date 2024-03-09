#pragma once

#include "Library/Area/AreaObj.h"

class StainArea : public al::AreaObj {
public:
    StainArea(const char* name);

    void init(const al::AreaInitInfo& areaInitInfo) override;

public:
    s32 mStainType = 0;
};
