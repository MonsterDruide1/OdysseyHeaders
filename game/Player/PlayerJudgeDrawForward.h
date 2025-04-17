#pragma once

#include "Player/IJudge.h"

namespace al {
class LiveActor;
}

class PlayerJudgeDeadWipeStart;

class PlayerJudgeDrawForward : public IJudge {
public:
    PlayerJudgeDrawForward(const al::LiveActor* playerActor,
                           const PlayerJudgeDeadWipeStart* playerJudgeDeadWipeStart);
    void reset() override;
    void update() override;
    bool judge() const override;

public:
    const al::LiveActor* mPlayerActor;
    const PlayerJudgeDeadWipeStart* mPlayerJudgeDeadWipeStart;
};
