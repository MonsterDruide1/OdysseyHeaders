#pragma once

#include "Library/Area/AreaObj.h"

class NpcForceMaterialCodeArea : public al::AreaObj {
public:
    NpcForceMaterialCodeArea(const char* name);

    void init(const al::AreaInitInfo& areaInitInfo) override;

public:
    const char* mMaterialCodeName = nullptr;
};
