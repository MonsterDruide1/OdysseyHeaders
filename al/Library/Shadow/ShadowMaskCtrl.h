#pragma once

#include <container/seadPtrArray.h>
#include <math/seadMatrix.h>

namespace al {

class ByamlIter;
class LiveActor;
class ShadowMaskBase;
class ShadowMaskCastOvalCylinder;
class ShadowMaskCube;
class ShadowMaskCylinder;
class ShadowMaskSphere;
struct ActorInitInfo;

class ShadowMaskCtrl {
public:
    ShadowMaskCtrl(bool);
    void appendShadowMask(ShadowMaskBase*);
    ShadowMaskBase* findShadowMask(const char*);
    void hide();
    bool init(LiveActor*, const ActorInitInfo&, const ByamlIter&);
    bool init(LiveActor*, s32);
    void initAfterPlacement();
    void initShadowMaskNum(s32);
    void invalidate();
    bool isHide();
    void setupShadowMaskCastOvalCylinderParam(ShadowMaskCastOvalCylinder*);
    void setupShadowMaskCubeParam(ShadowMaskCube*);
    void setupShadowMaskCylinderParam(ShadowMaskCylinder*);
    void setupShadowMaskSphereParam(ShadowMaskSphere*);
    void show();
    void validate();

public:
    sead::PtrArray<ShadowMaskBase> mShadowMasks;
    sead::Matrix34f mMtx;
    void* mLiveActor;
    bool mIsIgnoreShadowMaskYaml;
};

}  // namespace al
