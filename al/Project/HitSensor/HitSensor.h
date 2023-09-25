#pragma once

#include <math/seadMatrix.h>
#include <math/seadVector.h>
#include "Project/HitSensor/SensorHitGroup.h"

namespace al {
class LiveActor;

class HitSensor {
public:
    HitSensor(al::LiveActor*, const char*, u32, f32, unsigned short, const sead::Vector3<f32>*,
              const sead::Matrix34<f32>*, const sead::Vector3<f32>&);

    bool trySensorSort();
    void setFollowPosPtr(const sead::Vector3<f32>*);
    void setFollowMtxPtr(const sead::Matrix34<f32>*);
    void validate();
    void invalidate();
    void validateBySystem();
    void invalidateBySystem();
    void update();
    void addHitSensor(al::HitSensor*);

    const char* mName;  // _0
    s32 _8;
    f32 _C;
    f32 _10;
    f32 _14;
    f32 _18;
    unsigned short mMaxSensorCount;  // _1C
    unsigned short mSensorCount;     // _1E
    al::HitSensor** mSensors;        // _20
    unsigned long _28;
    al::SensorHitGroup* mHitGroup;  // _30
    bool mIsValidBySystem;          // _38
    bool mIsValid;                  // _39
    bool _3A[4];                    // unknown type
    unsigned short _3E;
    al::LiveActor* mParentActor;            // _40
    const sead::Vector3<f32>* mFollowPos;   // _48
    const sead::Matrix34<f32>* mFollowMtx;  // _50
};
};  // namespace al
