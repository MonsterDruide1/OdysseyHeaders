#pragma once

#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

class SenobiLeaf : public al::LiveActor {
public:
    SenobiLeaf(const char* actorName);

    void init(const al::ActorInitInfo& info) override;
    void calcAnim() override;

    void updatePose();
    void registerToHost(al::LiveActor*, bool);

public:
    al::LiveActor* mHostActor = nullptr;
    f32 mLocalZRotator = 0.0f;
    f32 mYDegree = 0.0f;
    sead::Vector3f mUp = sead::Vector3f::ey;
};
