#pragma once

#include <math/seadVector.h>

#include "Library/Area/IUseAreaObj.h"
#include "Library/HostIO/HioNode.h"

namespace al {
class AreaObj;
class AreaObjDirector;
class AreaObjGroup;

class CameraAngleVerticalRequester : public HioNode, public IUseAreaObj {
public:
    CameraAngleVerticalRequester();
    AreaObjDirector* getAreaObjDirector() const override;
    void init(AreaObjDirector* areaObjDirector);
    void initAfterPlacement();
    void update(const sead::Vector3f& position);

public:
    s32 mFramesUnchanged = 0;
    f32 mAngleVertical = 0.0f;
    const AreaObj* mRequestArea = nullptr;
    const AreaObjGroup* mRequestAreaGroup = nullptr;
    AreaObjDirector* mAreaObjDirector = nullptr;
};
}  // namespace al
