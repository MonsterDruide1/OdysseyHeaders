#pragma once

#include "Library/Nerve/NerveStateBase.h"

namespace al {
class LiveActor;
}
class PlayerConst;
class IUsePlayerCollision;
class PlayerInput;
class PlayerActionDiveInWater;
class PlayerAnimator;

class PlayerStateHeadSliding : public al::ActorStateBase {
public:
    PlayerStateHeadSliding(al::LiveActor* player, const PlayerConst* pConst,
                           const IUsePlayerCollision* collider, const PlayerInput* input,
                           const PlayerActionDiveInWater* actionDiveInWater,
                           PlayerAnimator* animator);

    void appear() override;
    void kill() override;

    bool isEnableDiveInWater() const;

    void exeDive();

public:
    const PlayerConst* mConst;
    const IUsePlayerCollision* mCollider;
    const PlayerInput* mInput;
    const PlayerActionDiveInWater* mActionDiveInWater;
    PlayerAnimator* mAnimator;
    bool mIsEnableDiveInWater = false;
};
