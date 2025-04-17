#pragma once

#include <math/seadVector.h>

namespace al {
class AreaObj;
class AreaObjGroup;
class SwitchAreaTargetInfo;

class SwitchKeepOnAreaGroup {
public:
    SwitchKeepOnAreaGroup(AreaObjGroup* areaObjGroup);

    void update(const SwitchAreaTargetInfo* info);
    void update(const sead::Vector3f& playerPos);

    virtual void selectTargetPosArray(bool* outCheckAllPos, sead::Vector3f** outTargetPos,
                                      s32* outTargetPosCount, const AreaObj* areaObj,
                                      const SwitchAreaTargetInfo* info);

    virtual bool isExternalCondition() const { return true; }

public:
    AreaObjGroup* mAreaObjGroup;
    AreaObj** mOnAreaObjs = nullptr;
    s32 mOnAreaObjSize = 0;
    s32 mOnAreaObjCount = 0;
};

static_assert(sizeof(SwitchKeepOnAreaGroup) == 0x20);
}  // namespace al
