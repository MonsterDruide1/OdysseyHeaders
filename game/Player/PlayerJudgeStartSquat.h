#pragma once

#include "Player/IJudge.h"

class PlayerInput;
class PlayerCounterForceRun;
class PlayerCarryKeeper;

class PlayerJudgeStartSquat : public IJudge {
public:
    PlayerJudgeStartSquat(const PlayerInput*, const PlayerCounterForceRun*,
                          const PlayerCarryKeeper*);
    void reset() override;
    void update() override;
    bool judge() const override;

public:
    const PlayerInput* mInput;
    const PlayerCounterForceRun* mCounterForceRun;
    const PlayerCarryKeeper* mCarryKeeper;
};

static_assert(sizeof(PlayerJudgeStartSquat) == 0x20);
