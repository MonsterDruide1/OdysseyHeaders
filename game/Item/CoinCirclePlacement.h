#pragma once

#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

class Coin;

class CoinCirclePlacement : public al::LiveActor {
public:
    CoinCirclePlacement(const char* name);

    void init(const al::ActorInitInfo& initInfo) override;

    void listenAppear();
    void exeMove();

public:
    Coin** mCoinArray = nullptr;
    s32 mCoinNum = 0;
    f32 mRotateVelocity = 0.0f;
    sead::Vector3f mSide = sead::Vector3f::zero;
    sead::Vector3f mUp = sead::Vector3f::zero;
    sead::Vector3f mFront = sead::Vector3f::zero;
    f32 mCurrentAngle = 0.0f;
    char pad[12];
    f32 mCircleXWidth = 0.0f;
    f32 mCircleZWidth = 0.0f;
    sead::Vector3f _154 = sead::Vector3f::zero;
};
