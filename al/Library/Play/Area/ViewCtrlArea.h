#pragma once

#include "Library/Area/AreaObj.h"

namespace al {
class PlacementId;

class ViewCtrlArea : public AreaObj {
public:
    ViewCtrlArea(const char* name);

    void init(const AreaInitInfo& areaInitInfo) override;

public:
    PlacementId* mPlacementId;
};
}  // namespace al
