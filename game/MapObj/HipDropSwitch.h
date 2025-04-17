#pragma once

#include "Library/LiveActor/LiveActor.h"

class HipDropSwitch : public al::LiveActor {
public:
    HipDropSwitch(const char*);
    void init(const al::ActorInitInfo&) override;
    void reset();
    void control() override;
    bool isOn() const;
    bool receiveMsg(const al::SensorMsg*, al::HitSensor* self, al::HitSensor* other) override;
    void startClipped() override;
    bool isOnWait() const;
    void writeSave();
    void validateSwitchByCage();
    void invalidateSwitchByCage();
    void exeOffWait();
    void exeReactionLand();
    void exeOn();
    void exeOnWait();
    void exeDisable();

public:
    void* _108;
    s32 _110;
    s32 _114;
    bool _118;
    s32 _11c;
    s32 _120;
    void* _128;
};

static_assert(sizeof(HipDropSwitch) == 0x130);
