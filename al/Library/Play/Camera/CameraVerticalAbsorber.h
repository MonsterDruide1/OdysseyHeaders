#pragma once

#include <basis/seadTypes.h>
#include <gfx/seadCamera.h>
#include <gfx/seadProjection.h>
#include <math/seadVector.h>

#include "Library/Nerve/NerveExecutor.h"

namespace al {
class ByamlIter;
class CameraPoser;
struct CameraStartInfo;

class CameraVerticalAbsorber : public NerveExecutor {
public:
    CameraVerticalAbsorber(const CameraPoser* cameraParent, bool isCameraPosAbsorb);
    ~CameraVerticalAbsorber();
    void exeAbsorb();
    void exeFollow();
    void exeFollowAbsolute();
    void exeFollowClimbPole();
    void exeFollowGround();
    void invalidate();
    bool isAbsorbing() const;
    bool isValid() const;
    void liberateAbsorb();
    void load(const ByamlIter&);
    void makeLookAtCamera(sead::LookAtCamera*) const;
    void start(const sead::Vector3f&, const CameraStartInfo&);
    void tryResetAbsorbVecIfInCollision(const sead::Vector3f&);
    void update();

public:
    const CameraPoser* mCameraPoser;
    sead::LookAtCamera mLookAtCamera;
    sead::PerspectiveProjection mProjection;
    sead::Vector3f mTargetInterp;
    f32 mLerp1;
    f32 mAbsorbScreenPosUp;
    f32 mAbsorbScreenPosDown;
    bool mIsAdvanceAbsorbUp;
    f32 mAdvanceAbsorbScreenPosUp;
    bool mIsExistCollisionUnderTarget;
    sead::Vector3f mUnderTargetCollisionPos;
    sead::Vector3f mUnderTargetCollisionNormal;
    f32 mLerp2;
    f32 mKeepInFrameOffsetUp;
    f32 mKeepInFrameOffsetDown;
    f32 mHighJumpJudgeSpeedV;
    sead::Vector3f mPrevTargetTrans;
    sead::Vector3f mTargetFront;
    sead::Vector3f mPrevTargetFront;
    bool mIsNoCameraPosAbsorb;
    bool mIsInvalidated;
    bool unk_unusedBool;
    bool mIsStopUpdate;
    bool mIsKeepInFrame;
};

static_assert(sizeof(CameraVerticalAbsorber) == 0x1B0);

}  // namespace al
