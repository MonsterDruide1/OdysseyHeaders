#pragma once

#include "Library/LiveActor/LiveActor.h"

class VolleyballNet : public al::LiveActor {
public:
    VolleyballNet(const char* name);
    void init(const al::ActorInitInfo& initInfo) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeWait();
    void exeReaction();

public:
    s32 mReactionFrames = 0;
};
