#pragma once

#include "Library/LiveActor/LiveActor.h"

class ItemGenerator;

class TrampleBush : public al::LiveActor {
public:
    TrampleBush(const char* actorName);

    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;

    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;


    void exeWait();
    void exeReaction();
    void exeTrample();

public:
    ItemGenerator* mItemGenerator = nullptr;
    sead::Vector3f mAttackerTrans;
};
