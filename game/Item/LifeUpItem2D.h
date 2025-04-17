#pragma once

#include "Library/LiveActor/LiveActor.h"

#include "Util/IUseDimension.h"

namespace al {
class HitSensor;
class NerveStateBase;
}  // namespace al

class ActorDimensionKeeper;

class LifeUpItem2D : public al::LiveActor, public IUseDimension {
public:
    LifeUpItem2D(const char* name);

    void init(const al::ActorInitInfo& initInfo) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    ActorDimensionKeeper* getActorDimensionKeeper() const override;

    void appearPopUp();
    void appearAmiiboTouch();
    void get();

    void exePopUp();
    void exeWait();
    void exeGet();
    void exeAutoGetDemo();

    void setBool130(bool value) { _130 = value; }

public:
    al::NerveStateBase* mNerveStateBase = nullptr;
    al::HitSensor* mHitSensor = nullptr;
    s32 _120 = 0;
    ActorDimensionKeeper* mDimensionKeeper = nullptr;
    bool _130 = false;
};
