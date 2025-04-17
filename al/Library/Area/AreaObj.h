#pragma once

#include <math/seadMatrix.h>
#include <math/seadVector.h>

#include "Library/HostIO/HioNode.h"
#include "Library/Scene/IUseSceneObjHolder.h"
#include "Library/Stage/IUseStageSwitch.h"

namespace al {

class AreaInitInfo;
class AreaShape;
class PlacementInfo;
class SceneObjHolder;
class StageSwitchKeeper;

class AreaObj : public IUseStageSwitch, public IUseSceneObjHolder, public HioNode {
public:
    AreaObj(const char* name);

    const char* getName() const override;
    StageSwitchKeeper* getStageSwitchKeeper() const override;
    void initStageSwitchKeeper() override;
    virtual void init(const AreaInitInfo& info);
    virtual bool isInVolume(const sead::Vector3f& pos) const;
    virtual bool isInVolumeOffset(const sead::Vector3f& pos, f32 offset) const;
    SceneObjHolder* getSceneObjHolder() const override;
    void validate();
    void invalidate();

    const PlacementInfo& getPlacementInfo() const { return *mPlacementInfo; }

    AreaShape* getAreaShape() const { return mAreaShape; }

    const sead::Matrix34f& getAreaMtx() const { return mAreaTR; }

    s32 getPriority() { return mPriority; };

public:
    const char* mName;
    AreaShape* mAreaShape = nullptr;
    StageSwitchKeeper* mStageSwitchKeeper = nullptr;
    SceneObjHolder* mSceneObjHolder = nullptr;
    sead::Matrix34f mAreaTR = sead::Matrix34f::ident;
    PlacementInfo* mPlacementInfo = nullptr;
    s32 mPriority = -1;
    bool mIsValid = true;
};
}  // namespace al
