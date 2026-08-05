#pragma once

#include "Player/IJudge.h"

class PlayerStateDamageFire;

class PlayerJudgeEnablePeachAmiibo : public IJudge {
public:
    PlayerJudgeEnablePeachAmiibo(const PlayerStateDamageFire* state);

    void reset() override {}

    void update() override {}

    bool judge() const override;

public:
    const PlayerStateDamageFire* mState = nullptr;
};

static_assert(sizeof(PlayerJudgeEnablePeachAmiibo) == 0x10);
