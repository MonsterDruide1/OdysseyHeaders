#pragma once

#include "Player/IJudge.h"

namespace al {
class LiveActor;
}
class IUsePlayerCollision;
class PlayerConst;
class PlayerCounterForceRun;
class PlayerInput;

class PlayerJudgeStartRun : public IJudge {
public:
    PlayerJudgeStartRun(const al::LiveActor* player, const PlayerConst* pConst,
                        const IUsePlayerCollision* collision, const PlayerInput* input,
                        const PlayerCounterForceRun* counterForceRun,
                        const IJudge* judgeWaterSurfaceRun);

    void reset() override;
    void update() override;
    bool judge() const override;

public:
    const al::LiveActor* mPlayer;
    const IUsePlayerCollision* mCollision;
    const PlayerInput* mInput;
    const PlayerCounterForceRun* mCounterForceRun;
    const IJudge* mJudgeForceLand;
};
