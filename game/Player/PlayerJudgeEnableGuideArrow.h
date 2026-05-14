#pragma once

#include "Player/IJudge.h"

class PlayerPuppet;

class PlayerJudgeEnableGuideArrow : public IJudge {
public:
    PlayerJudgeEnableGuideArrow(const PlayerPuppet* playerPuppet);

    void reset() override {}

    void update() override {}

    bool judge() const override;

public:
    const PlayerPuppet* mPlayerPuppet = nullptr;
};

static_assert(sizeof(PlayerJudgeEnableGuideArrow) == 0x10);
